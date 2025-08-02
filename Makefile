# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 22:29:30 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/08/02 23:00:53 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = libft.a
TESTS_BIN		= run_tests
AR              = ar rcs
CFLAGS          = -Wall -Wextra -Werror -std=c99 -march=native -pedantic -Wshadow -Wconversion \
                  -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wformat=2 \
				  -Winline -Wsign-conversion -Wundef -Wcast-align -Wcast-qual -Wwrite-strings \
				  -Wuninitialized -Wdouble-promotion -Wvla -Wnull-dereference \
                  -Wold-style-definition -Wpadded -D_DEFAULT_SOURCE $(INCLUDE_FLAGS)
DEBUG_FLAGS     = -g3 -O0 -DDEBUG

CC				= clang
RM				= rm -f
RMDIR			= rm -rf
MKDIR			= mkdir -p
FIND_SRCS		= $(shell find $(SRCS_DIR) -name "*.c" -type f 2>/dev/null | sed 's|$(SRCS_DIR)/||')
FIND_TESTS		= $(shell find $(SRCS_DIR) -name "*.c" -type f 2>/dev/null | sed 's|$(TESTS_DIR)/||')
PATH_SEP		= /

SRCS_DIR		= src
INCS_DIR		= include
OBJS_DIR        = objs
DEBUG_DIR       = debug_objs
TESTS_DIR		= test

SRCS            = $(FIND_SRCS)
TESTS_SRCS		= $(FIND_TESTS)

OBJS            = $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
DEBUG_OBJS      = $(addprefix $(DEBUG_DIR)/, ${SRCS:.c=.o})

SUB_DIRS = $(shell find $(INCS_DIR) -type d 2>/dev/null)

INCLUDE_FLAGS   = $(addprefix -I, $(SUB_DIRS))

OBJ_SUBDIRS     = $(sort $(dir $(OBJS)))
DEBUG_SUBDIRS   = $(sort $(dir $(DEBUG_OBJS)))

ifeq ($(DETECTED_OS),Darwin)
    DEBUGGER = lldb
    DEBUG_FLAGS += -g
    DEBUGGER_EXEC = lldb --
else
    DEBUGGER = gdb
    DEBUG_FLAGS += -ggdb
    DEBUGGER_EXEC = gdb --args
endif

SANITIZE := $(shell $(CC) -fsanitize=address -x c -c /dev/null -o /dev/null 2>/dev/null && echo "-fsanitize=address -fsanitize=undefined" || echo "")

TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

all:	create_dirs $(NAME)

create_dirs:
	@$(MKDIR) $(OBJ_SUBDIRS)
	@echo "Created object directories"

create_debug_dirs:
	@$(MKDIR) $(DEBUG_SUBDIRS)
	@echo "Created debug object directories"

$(OBJS_DIR):
	@$(MKDIR) $@
	@echo "Created objects directory"

$(DEBUG_DIR):
	@$(MKDIR) $@
	@echo "Created debug objects directory"

$(NAME): ${OBJS}
	@echo "Compiling library..."
	@$(AR) ${NAME} ${OBJS}
	@echo "Library $(NAME) successfully created"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)))
	@printf "[%3d%%] Compiling %s\n" $(PROGRESS) "$<"
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n[100%%] Compile complete!\n"; fi

$(DEBUG_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)))
	@printf "[%3d%%] Debug-compiling %-30s\r" $(PROGRESS) "$<"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n[100%%] Debug compile complete!\n"; fi

debug: CURRENT_FILE := 0
debug: create_debug_dirs debug_lib
	@echo "Debug build complete for $(DEBUGGER)"
	@echo "Run your program with: $(DEBUGGER_EXEC) ./your_program"
	@$(MAKE) clean

debug_lib: $(DEBUG_OBJS)
	@echo "Compiling debug library..."
	@$(AR) $(NAME) $(DEBUG_OBJS)


sanitize: CFLAGS += $(SANITIZE)
sanitize: CURRENT_FILE := 0
sanitize: fclean $(OBJS_DIR)
	@if [ -z "$(SANITIZE)" ]; then \
		echo "Address sanitizer not supported on this system"; \
		$(MAKE) all; \
	else \
		echo "Compiling with Address Sanitizer"; \
		$(MAKE) all; \
		echo "Address Sanitizer build complete"; \
	fi

clean:
	@$(RMDIR) $(OBJS_DIR) 2>/dev/null || true
	@$(RMDIR) $(DEBUG_DIR) 2>/dev/null || true
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME) 2>/dev/null || true
	@echo "Library $(NAME) removed"

re: fclean all

debug-vars:
	@echo "DETECTED_OS: $(DETECTED_OS)"
	@echo "SRCS_DIR: $(SRCS_DIR)"
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "OBJ_SUBDIRS: $(OBJ_SUBDIRS)"
	@echo "TOTAL_FILES: $(TOTAL_FILES)"

norm:
	norminette $$(find $(INCS_DIR) -type f -name "*.h")
	norminette $$(find $(SRCS_DIR) -type f -name "*.c")

tests: $(NAME)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -o $(TESTS_BIN) $(TESTS_SRCS) $(NAME) -lcriterion
	./$(TESTS_BIN)

info:
	@echo "┌───────────────────────────────────────────────────────┐"
	@echo "│             Makefile for libft                     	│"
	@echo "├───────────────────────────────────────────────────────┤"
	@echo "│ make        : compile the main library ($(NAME))   	│"
	@echo "│ make debug  : compile with debug symbols		│"
	@echo "│              (using $(DEBUGGER))				│"
	@echo "│ make sanitize: compile with address sanitizer   	│"
	@echo "│ make clean   : remove object files              	│"
	@echo "│ make fclean  : remove objects and library       	│"
	@echo "│ make re      : execute fclean then all          	│"
	@echo "│ make debug-vars: show variables for debugging	│"
	@echo "└───────────────────────────────────────────────────────┘"
	@echo "Detected OS: $(DETECTED_OS)"

.PHONY: all debug debug_lib sanitize clean fclean re info create_dirs create_debug_dirs debug-vars norm tests
