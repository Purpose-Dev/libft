# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 22:29:30 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/05/31 00:30:13 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project configuration
NAME            = libft.a
AR              = ar rcs
CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -std=c99 -pedantic -Wshadow -Wconversion \
                  -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
                  -Wold-style-definition
DEBUG_FLAGS     = -g3 -O0 -DDEBUG

# Source files and directories
SRCS_DIR		= srcs
INCS_DIR		= includes
OBJS_DIR        = objs
DEBUG_DIR       = debug_objs

SRCS            = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c  \
				  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				  ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				  ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS            = $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
DEBUG_OBJS      = $(addprefix $(DEBUG_DIR)/, ${SRCS:.c=.o})

# OS detection for debugger configuration
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
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
all:            $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $@
	@echo "Created objects directory"

$(DEBUG_DIR):
	@mkdir -p $@
	@echo "Created debug objects directory"

$(NAME): ${OBJS}
	@echo "Compiling library..."
	@$(AR) ${NAME} ${OBJS}
	@echo "✓ Library $(NAME) successfully created"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)))
	@printf "[%3d%%] Compiling %-30s\r" $(PROGRESS) "$<"
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n[100%%] Compile complete!\n"; fi

$(DEBUG_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)))
	@printf "[%3d%%] Debug-compiling %-30s\r" $(PROGRESS) "$<"
	@$(CC) $(CFLAGS) -I$(INCS_DIR) $(DEBUG_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then printf "\n[100%%] Debug compile complete!\n"; fi

debug: CURRENT_FILE := 0
debug: $(DEBUG_DIR) debug_lib
	@echo "✓ Debug build complete for $(DEBUGGER)"
	@echo "➤ Run your program with: $(DEBUGGER_EXEC) ./your_program"

debug_lib: $(DEBUG_OBJS)
	@echo "Compiling debug library..."
	@$(AR) $(NAME) $(DEBUG_OBJS)

sanitize: CFLAGS += $(SANITIZE)
sanitize: CURRENT_FILE := 0
sanitize: fclean $(OBJS_DIR)
	@if [ -z "$(SANITIZE)" ]; then \
		echo "⚠️  Address sanitizer not supported on this system"; \
		$(MAKE) all; \
	else \
		echo "➤ Compiling with Address Sanitizer"; \
		$(MAKE) all; \
		echo "✓ Address Sanitizer build complete"; \
	fi

clean:
	@$(RM) -rf $(OBJS_DIR)
	@$(RM) -rf $(DEBUG_DIR)
	@echo "✓ Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "✓ Library $(NAME) removed"

re: fclean all

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
	@echo "└───────────────────────────────────────────────────────┘"

.PHONY: all debug debug_lib sanitize clean fclean re info
