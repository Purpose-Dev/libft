# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 22:29:30 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/05/31 23:17:42 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    UNAME_S := $(shell uname -s 2>/dev/null)
    ifeq ($(UNAME_S),Linux)
        DETECTED_OS := Linux
    endif
    ifeq ($(UNAME_S),Darwin)
        DETECTED_OS := Darwin
    endif
    ifeq ($(UNAME_S),CYGWIN*)
        DETECTED_OS := Cygwin
    endif
    ifeq ($(UNAME_S),MINGW32*)
        DETECTED_OS := MinGW
    endif
    ifeq ($(UNAME_S),MINGW64*)
        DETECTED_OS := MinGW
    endif
endif

ifeq ($(DETECTED_OS),Windows)
    CC = gcc
    RM = del /Q
    RMDIR = rmdir /S /Q
    MKDIR = if not exist
    MKDIR_CMD = mkdir
    SHELL = cmd
    FIND_SRCS_RAW = $(wildcard $(SRCS_DIR)/*.c) $(wildcard $(SRCS_DIR)/*/*.c) $(wildcard $(SRCS_DIR)/*/*/*.c)
    FIND_SRCS = $(patsubst $(SRCS_DIR)/%,%,$(FIND_SRCS_RAW))
    FIND_INCS_RAW = $(wildcard $(INCS_DIR)/*.h) $(wildcard $(INCS_DIR)/*/*.h) $(wildcard $(INCS_DIR)/*/*/*.h)
    PATH_SEP = \\
else
    CC = cc
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p
    MKDIR_CMD =
    FIND_SRCS = $(shell find $(SRCS_DIR) -name "*.c" -type f 2>/dev/null | sed 's|$(SRCS_DIR)/||')
    PATH_SEP = /
endif

# Project configuration
NAME            = libft.a
AR              = ar rcs
CFLAGS          = -Wall -Wextra -Werror -std=c99 -march=native -pedantic -Wshadow -Wconversion \
                  -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
                  -Wold-style-definition $(INCLUDE_FLAGS)
DEBUG_FLAGS     = -g3 -O0 -DDEBUG

# Source files and directories
SRCS_DIR		= srcs
INCS_DIR		= includes
OBJS_DIR        = objs
DEBUG_DIR       = debug_objs

SRCS            = $(FIND_SRCS)

OBJS            = $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
DEBUG_OBJS      = $(addprefix $(DEBUG_DIR)/, ${SRCS:.c=.o})

ifeq ($(DETECTED_OS),Windows)
    SUB_DIRS = $(INCS_DIR)
else
    SUB_DIRS = $(shell find $(INCS_DIR) -type d 2>/dev/null)
endif

INCLUDE_FLAGS   = $(addprefix -I, $(SUB_DIRS))

OBJ_SUBDIRS     = $(sort $(dir $(OBJS)))
DEBUG_SUBDIRS   = $(sort $(dir $(DEBUG_OBJS)))

# OS detection for debugger configuration
ifeq ($(DETECTED_OS),Darwin)
    DEBUGGER = lldb
    DEBUG_FLAGS += -g
    DEBUGGER_EXEC = lldb --
else
    DEBUGGER = gdb
    DEBUG_FLAGS += -ggdb
    DEBUGGER_EXEC = gdb --args
endif

# Determine if address sanitizer is available
SANITIZE := $(shell $(CC) -fsanitize=address -x c -c /dev/null -o /dev/null 2>/dev/null && echo "-fsanitize=address -fsanitize=undefined" || echo "")

# Progress counter
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

# Main targets
all:	create_dirs $(NAME)

ifeq ($(DETECTED_OS),Windows)
create_dirs:
	@for %%d in ($(OBJ_SUBDIRS)) do @if not exist "%%d" mkdir "%%d" 2>nul || echo >nul
	@echo Created object directories
else
create_dirs:
	@$(MKDIR) $(OBJ_SUBDIRS)
	@echo "Created object directories"
endif

ifeq ($(DETECTED_OS),Windows)
create_debug_dirs:
	@for %%d in ($(DEBUG_SUBDIRS)) do @if not exist "%%d" mkdir "%%d" 2>nul || echo >nul
	@echo Created debug object directories
else
create_debug_dirs:
	@$(MKDIR) $(DEBUG_SUBDIRS)
	@echo "Created debug object directories"
endif

$(OBJS_DIR):
ifeq ($(DETECTED_OS),Windows)
	@$(MKDIR) "$@" $(MKDIR_CMD) "$@" 2>nul || echo >nul
else
	@$(MKDIR) $@
endif
	@echo "Created objects directory"

$(DEBUG_DIR):
ifeq ($(DETECTED_OS),Windows)
	@$(MKDIR) "$@" $(MKDIR_CMD) "$@" 2>nul || echo >nul
else
	@$(MKDIR) $@
endif
	@echo "Created debug objects directory"

$(NAME): ${OBJS}
	@echo "Compiling library..."
	@$(AR) ${NAME} ${OBJS}
	@echo "Library $(NAME) successfully created"

ifeq ($(DETECTED_OS),Windows)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)" 2>nul || echo >nul
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(DEBUG_DIR)/%.o: $(SRCS_DIR)/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)" 2>nul || echo >nul
	@echo Debug-compiling $<
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@
else
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)))
	@printf "[%3d%%] Compiling %-30s\r" $(PROGRESS) "$<"
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n[100%%] Compile complete!\n"; fi

$(DEBUG_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)))
	@printf "[%3d%%] Debug-compiling %-30s\r" $(PROGRESS) "$<"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n[100%%] Debug compile complete!\n"; fi
endif

debug: CURRENT_FILE := 0
debug: create_debug_dirs debug_lib
	@echo "Debug build complete for $(DEBUGGER)"
	@echo "Run your program with: $(DEBUGGER_EXEC) ./your_program"

debug_lib: $(DEBUG_OBJS)
	@echo "Compiling debug library..."
	@$(AR) $(NAME) $(DEBUG_OBJS)

ifeq ($(DETECTED_OS),Windows)
sanitize:
	@echo "Address sanitizer not supported in this Windows environment"
	@echo "Building without sanitizer..."
	@$(MAKE) fclean
	@$(MAKE) all
else
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
endif

ifeq ($(DETECTED_OS),Windows)
clean:
	@if exist "$(OBJS_DIR)" $(RMDIR) "$(OBJS_DIR)" 2>nul || echo >nul
	@if exist "$(DEBUG_DIR)" $(RMDIR) "$(DEBUG_DIR)" 2>nul || echo >nul
	@echo Objects removed

fclean: clean
	@if exist "$(NAME)" $(RM) "$(NAME)" 2>nul || echo >nul
	@echo Library $(NAME) removed
else
clean:
	@$(RMDIR) $(OBJS_DIR) 2>/dev/null || true
	@$(RMDIR) $(DEBUG_DIR) 2>/dev/null || true
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME) 2>/dev/null || true
	@echo "Library $(NAME) removed"
endif

re: fclean all

debug-vars:
	@echo "DETECTED_OS: $(DETECTED_OS)"
	@echo "SRCS_DIR: $(SRCS_DIR)"
ifeq ($(DETECTED_OS),Windows)
	@echo "FIND_SRCS_RAW: $(FIND_SRCS_RAW)"
	@echo "FIND_INCS_RAW: $(FIND_INCS_RAW)"
endif
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "OBJ_SUBDIRS: $(OBJ_SUBDIRS)"
	@echo "TOTAL_FILES: $(TOTAL_FILES)"

norm:
ifeq ($(DETECTED_OS),Windows)
	norminette -RCheckDefine $(FIND_INCS_RAW)
	norminette -RCheckForbiddenSourceHeaders $(FIND_SRCS_RAW)
else
	norminette -RCheckDefine $$(find $(INCS_DIR) -type f -name "*.h")
	norminette -RCheckForbiddenSourceHeaders $$(find $(SRCS_DIR) -type f -name "*.c")
endif

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

.PHONY: all debug debug_lib sanitize clean fclean re info create_dirs create_debug_dirs debug-vars norm