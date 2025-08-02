# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 22:29:30 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/08/03 00:22:50 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
TESTS_BIN		= run_tests
TESTS_SANITIZE	= run_tests_sanitize

AR				= ar rcs
CC				= clang
CXX				= c++
RM				= rm -f
RMDIR			= rm -rf
MKDIR			= mkdir -p

# Directories
SRCS_DIR		= src
INCS_DIR		= include
TESTS_DIR		= test
OBJS_DIR		= objs
DEBUG_DIR		= debug_objs
TESTS_OBJS_DIR	= tests_objs

# Source files discovery
FIND_SRCS		= $(shell find $(SRCS_DIR) -name "*.c" -type f 2>/dev/null | sed 's|$(SRCS_DIR)/||')
FIND_TESTS		= $(shell find $(TESTS_DIR) -name "*.cpp" -type f 2>/dev/null | sed 's|$(TESTS_DIR)/||')

SRCS			= $(FIND_SRCS)
TESTS_SRCS		= $(FIND_TESTS)

OBJS			= $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
DEBUG_OBJS		= $(addprefix $(DEBUG_DIR)/, ${SRCS:.c=.o})
TESTS_OBJS		= $(addprefix $(TESTS_OBJS_DIR)/, ${TESTS_SRCS:.cpp=.o})

# Include directories
SUB_DIRS		= $(shell find $(INCS_DIR) -type d 2>/dev/null)
INCLUDE_FLAGS	= $(addprefix -I, $(SUB_DIRS))

OBJ_SUBDIRS		= $(sort $(dir $(OBJS)))
DEBUG_SUBDIRS	= $(sort $(dir $(DEBUG_OBJS)))
TEST_SUBDIRS	= $(sort $(dir $(TESTS_OBJS)))

# Compilation flags
CFLAGS			= -Wall -Wextra -Werror -std=c99 -march=native -pedantic -Wshadow -Wconversion \
                  -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wformat=2 \
				  -Winline -Wsign-conversion -Wundef -Wcast-align -Wcast-qual -Wwrite-strings \
				  -Wuninitialized -Wdouble-promotion -Wvla -Wnull-dereference \
                  -Wold-style-definition -Wpadded -D_DEFAULT_SOURCE $(INCLUDE_FLAGS)

CXX_FLAGS		= -Wall -Wextra -Werror -std=c++17 -march=native -pedantic $(INCLUDE_FLAGS)

DEBUG_FLAGS		= -g3 -O0 -DDEBUG
RELEASE_FLAGS	= -O3 -flto -funroll-loops -fomit-frame-pointer

GTEST_FLAGS		= -lgtest -lgtest_main -lpthread

# Platform detection
ifeq ($(DETECTED_OS),Darwin)
    DEBUGGER = lldb
    DEBUG_FLAGS += -g
    DEBUGGER_EXEC = lldb --
else
    DEBUGGER = gdb
    DEBUG_FLAGS += -ggdb
    DEBUGGER_EXEC = gdb --args
endif

# Sanitizer detection
SANITIZE		:= $(shell $(CC) -fsanitize=address -x c -c /dev/null -o /dev/null 2>/dev/null && echo "-fsanitize=address -fsanitize=undefined" || echo "")

# Progress Tracking
TOTAL_FILES		:= $(words $(SRCS))
TOTAL_TESTS		:= $(words $(TESTS_SRCS))
CURRENT_FILE	:= 0

# Main targets
all:	create_dirs $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling library..."
	@$(AR) ${NAME} ${OBJS}
	@echo "Library $(NAME) successfully created"

# Directory creation
create_dirs:
	@$(MKDIR) $(OBJ_SUBDIRS)
	@echo "Created objects directories"

create_debug_dirs:
	@$(MKDIR) $(DEBUG_SUBDIRS)
	@echo "Created debug objects directories"

create_tests_dirs:
	@$(MKDIR) $(TEST_SUBDIRS)
	@echo "Created tests objects directories"

# Compilation rules
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

$(TESTS_OBJS_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@$(eval PROGRESS=$(shell expr $(CURRENT_FILE) \* 100 / $(TOTAL_TESTS)))
	@printf "[%3d%%] Compiling test %s\n" $(PROGRESS) "$<"
	@$(CXX) $(CXX_FLAGS) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_TESTS) ]; then printf "\n[100%%] Tests compile complete!\n"; fi

# Test targets
tests: create_dirs $(NAME) create_tests_dirs $(TESTS_OBJS)
	@echo "Linking tests..."
	@$(CXX) $(CXX_FLAGS) -o $(TESTS_BIN) $(TESTS_OBJS) $(NAME) $(GTEST_FLAGS)
	@echo "Running tests..."
	@./$(TESTS_BIN)

tests-build: create_dirs $(NAME) create_tests_dirs $(TESTS_OBJS)
	@echo "Linking tests..."
	@$(CXX) $(CXX_FLAGS) -o $(TESTS_BIN) $(TESTS_OBJS) $(NAME) $(GTEST_FLAGS)
	@echo "Test binary $(TESTS_BIN) created"

tests-run: tests-build
	@echo "Running tests..."
	@./$(TESTS_BIN)

tests-verbose: tests-build
	@echo "Running tests with verbose output..."
	@./$(TESTS_BIN) --gtest_verbose

tests-filter: tests-build
	@echo "Usage: make tests-filter FILTER=TestSuiteName*"
	@if [ -n "$(FILTER)" ]; then \
		echo "Running tests matching: $(FILTER)"; \
		./$(TESTS_BIN) --gtest_filter="$(FILTER)"; \
	else \
		echo "Please specify FILTER=pattern"; \
		echo "Example: make tests-filter FILTER='*Strlen*'"; \
	fi

tests-sanitize: CFLAGS += $(SANITIZE)
tests-sanitize: CXX_FLAGS += $(SANITIZE)
tests-sanitize: fclean
	@if [ -z "$(SANITIZE)" ]; then \
		echo "Address sanitizer not supported on this system"; \
		$(MAKE) tests; \
	else \
		echo "Compiling with Address Sanitizer"; \
		$(MAKE) $(NAME); \
		$(MAKE) create_tests_dirs; \
		$(MAKE) CURRENT_FILE=0 tests-sanitize-compile; \
		$(CXX) $(CXX_FLAGS) -o $(TESTS_SANITIZE) $(TESTS_OBJS) $(NAME) $(GTEST_FLAGS); \
		echo "Running sanitized tests..."; \
		./$(TESTS_SANITIZE); \
	fi

tests-sanitize-compile: $(TESTS_OBJS)

debug: CURRENT_FILE := 0
debug: create_debug_dirs debug_lib
	@echo "Debug build complete for $(DEBUGGER)"
	@echo "Run your program with: $(DEBUGGER_EXEC) ./your_program"
	@$(MAKE) clean

debug_lib: $(DEBUG_OBJS)
	@echo "Compiling debug library..."
	@$(AR) $(NAME) $(DEBUG_OBJS)

debug-tests: debug create_tests_dirs
	@echo "Compiling debug tests..."
	@$(MAKE) CURRENT_FILE=0 CXXFLAGS="$(CXXFLAGS) $(DEBUG_FLAGS)" $(TESTS_OBJS)
	@$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -o $(TESTS_BIN) $(TESTS_OBJS) $(NAME) $(GTEST_FLAGS)
	@echo "Debug tests ready. Run with: $(DEBUGGER_EXEC) ./$(TESTS_BIN)"

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
	@$(RMDIR) $(TESTS_OBJS_DIR) 2>/dev/null || true
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME) 2>/dev/null || true
	@$(RM) $(TESTS_BIN) 2>/dev/null || true
	@$(RM) $(TESTS_SANITIZE) 2>/dev/null || true
	@echo "Library and binaries removed"

re: fclean all

re-tests: fclean tests

debug-vars:
	@echo "DETECTED_OS: $(DETECTED_OS)"
	@echo "SRCS_DIR: $(SRCS_DIR)"
	@echo "TESTS_DIR: $(TESTS_DIR)"
	@echo "SRCS: $(SRCS)"
	@echo "TESTS_SRCS: $(TESTS_SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "TESTS_OBJS: $(TESTS_OBJS)"
	@echo "TOTAL_FILES: $(TOTAL_FILES)"
	@echo "TOTAL_TESTS: $(TOTAL_TESTS)"
	@echo "SANITIZE: $(SANITIZE)"

norm:
	@echo "Checking norminette..."
	@norminette $$(find $(INCS_DIR) -type f -name "*.h" 2>/dev/null) || true
	@norminette $$(find $(SRCS_DIR) -type f -name "*.c" 2>/dev/null) || true

check-gtest:
	@echo "Checking GTest installation..."
	@pkg-config --exists gtest && echo "✓ GTest found" || echo "✗ GTest not found. Install with: sudo dnf install gtest-devel"
	@echo "GTest version: $$(pkg-config --modversion gtest 2>/dev/null || echo 'not found')"

info:
	@echo "┌─────────────────────────────────────────────────────────────┐"
	@printf "│%*s%*s│\n" 30 "Makefile for libft" 31 ""
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Library targets:"
	@printf "│   %-19s : %-35s │\n" "make" "compile the main library ($(NAME))"
	@printf "│   %-19s : %-35s │\n" "make debug" "compile with debug symbols ($(DEBUGGER))"
	@printf "│   %-19s : %-35s │\n" "make sanitize" "compile with address sanitizer"
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Test targets:"
	@printf "│   %-19s : %-35s │\n" "make tests" "compile library + tests and run"
	@printf "│   %-19s : %-35s │\n" "make tests-build" "only compile tests binary"
	@printf "│   %-19s : %-35s │\n" "make tests-run" "run existing tests binary"
	@printf "│   %-19s : %-35s │\n" "make tests-verbose" "run tests with verbose output"
	@printf "│   %-19s : %-35s │\n" "make tests-filter" "run filtered tests (FILTER=pattern)"
	@printf "│   %-19s : %-35s │\n" "make tests-sanitize" "run sanitized tests"
	@printf "│   %-19s : %-35s │\n" "make debug-tests" "compile tests with debug symbols"
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Utility targets:"
	@printf "│   %-19s : %-35s │\n" "make clean" "remove object files"
	@printf "│   %-19s : %-35s │\n" "make fclean" "remove objects, library and bins"
	@printf "│   %-19s : %-35s │\n" "make re" "execute fclean then all"
	@printf "│   %-19s : %-35s │\n" "make re-tests" "execute fclean then tests"
	@printf "│   %-19s : %-35s │\n" "make norm" "run norminette on source files"
	@printf "│   %-19s : %-35s │\n" "make check-gtest" "verify GTest installation"
	@printf "│   %-19s : %-35s │\n" "make debug-vars" "show variables for debugging"
	@echo "└─────────────────────────────────────────────────────────────┘"
	@printf "Tests directory: %s/ (*.cpp files)\n" "$(TESTS_DIR)"

.PHONY: all debug debug_lib sanitize clean fclean re re-tests info create_dirs \
        create_debug_dirs create_tests_dirs debug-vars norm tests tests-build \
        tests-run tests-verbose tests-filter tests-sanitize debug-tests check-gtest