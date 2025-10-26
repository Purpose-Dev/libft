# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 22:29:30 by rel-qoqu          #+#    #+#              #
#    Updated: 2025/10/26 12:55:30 by rel-qoqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# Project
# ============================================================================ #
NAME					:= libft.a
DEBUG_NAME				:= libft_debug.a
SANITIZED_NAME			:= libft_sanitized.a

TESTS_BIN				:= run_tests
TESTS_DEBUG				:= run_tests_debug
TESTS_SANITIZE			:= run_tests_sanitize

# ============================================================================ #
# Compilers and tools
# ============================================================================ #
C_COMPILER				:= clang
CXX_COMPILER			:= c++
AR						:= ar rcs
RMF						:= rm -f
RMD						:= rm -rf
MKDIR					:= mkdir -p

# ============================================================================ #
# Directories
# ============================================================================ #
SOURCE_DIR				:= src
INCLUDE_DIR				:= include
TESTS_DIR				:= test
BUILD_DIR				:= build
LIB_BUILD_DIR			:= $(BUILD_DIR)/lib
LIB_BUILD_RELEASE_DIR	:= $(LIB_BUILD_DIR)/release
LIB_BUILD_DEBUG_DIR		:= $(LIB_BUILD_DIR)/debug
LIB_BUILD_SAN_DIR		:= $(LIB_BUILD_DIR)/san
TESTS_BUILD_DIR			:= $(BUILD_DIR)/tests
TESTS_BUILD_RELEASE_DIR	:= $(TESTS_BUILD_DIR)/release
TESTS_BUILD_DEBUG_DIR	:= $(TESTS_BUILD_DIR)/debug
TESTS_BUILD_SAN_DIR		:= $(TESTS_BUILD_DIR)/san

# ============================================================================ #
# Compiler flags (C)
# ============================================================================ #
WARN_FLAGS				:= -Wall -Wextra -Werror -Wshadow -Wformat=2 -Winline \
							-Wsign-conversion -Wconversion -Wcast-align -Wcast-qual \
							-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
							-Wold-style-definition -Wundef -Wnull-dereference -Wuninitialized \
							-Wwrite-strings -Wpadded -Wdouble-promotion -Wvla -pedantic
LIB_FLAGS				:= -pthread
DEPS_FLAGS				:= -MMD -MP
SUB_DIRS				:= $(shell find $(INCLUDE_DIR) -type d 2>/dev/null)
INCLUDE_FLAGS			:= $(addprefix -I, $(SUB_DIRS))
POSIX_FLAGS				:= -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700
C_FLAGS					:= $(WARN_FLAGS) $(LIB_FLAGS) $(INCLUDE_FLAGS) -std=c99 -march=native \
							 $(POSIX_FLAGS) $(DEPS_FLAGS) -fPIC

C_FLAGS_RELEASE			:= $(C_FLAGS) -O3 -DNDEBUG -flto -funroll-loops -fomit-frame-pointer
C_FLAGS_DEBUG			:= $(C_FLAGS) -g3 -Og -DDEBUG
C_FLAGS_SAN				:= $(C_FLAGS) -g -fsanitize=address,undefined -fno-omit-frame-pointer


# ============================================================================ #
# Compiler flags (CXX)
# ============================================================================ #
CXX_FLAGS				:= -Wall -Wextra -Werror -std=c++17 -march=native -pedantic\
							$(INCLUDE_FLAGS) $(DEPS_FLAGS)

CXX_FLAGS_RELEASE		:= $(CXX_FLAGS) -O3 -DNDEBUG -flto
CXX_FLAGS_DEBUG			:= $(CXX_FLAGS) -g3 -Og -DDEBUG
CXX_FLAGS_SAN			:= $(CXX_FLAGS) -g -fsanitize=address,undefined -fno-omit-frame-pointer

GTEST_FLAGS				:= -lgtest -lgtest_main -lpthread

# ============================================================================ #
# Source files discovery
# ============================================================================ #
FIND_SRCS				= $(shell find $(SOURCE_DIR) -name "*.c" -type f 2>/dev/null | sed 's|$(SOURCE_DIR)/||')
FIND_TESTS				= $(shell find $(TESTS_DIR) -name "*.cpp" -type f 2>/dev/null | sed 's|$(TESTS_DIR)/||')

SRCS					:= $(FIND_SRCS)
TESTS_SRCS				:= $(FIND_TESTS)

# ============================================================================ #
# Object and dependencies (library)
# ============================================================================ #
RELEASE_OBJS			:= $(addprefix $(LIB_BUILD_RELEASE_DIR)/, $(SRCS:.c=.o))
DEBUG_OBJS				:= $(addprefix $(LIB_BUILD_DEBUG_DIR)/, $(SRCS:.c=.o))
SAN_OBJS				:= $(addprefix $(LIB_BUILD_SAN_DIR)/, $(SRCS:.c=.o))

RELEASE_DEPS			:= $(RELEASE_OBJS:.o=.d)
DEBUG_DEPS				:= $(DEBUG_OBJS:.o=.d)
SAN_DEPS				:= $(SAN_OBJS:.o=.d)

# ============================================================================ #
# Object and dependencies (library)
# ============================================================================ #
TESTS_OBJS_RELEASE		:= $(addprefix $(TESTS_BUILD_RELEASE_DIR)/, $(TESTS_SRCS:.cpp=.o))
TESTS_OBJS_DEBUG		:= $(addprefix $(TESTS_BUILD_DEBUG_DIR)/, $(TESTS_SRCS:.cpp=.o))
TESTS_OBJS_SAN			:= $(addprefix $(TESTS_BUILD_SAN_DIR)/, $(TESTS_SRCS:.cpp=.o))

TESTS_DEPS_RELEASE		:= $(TESTS_OBJS_RELEASE:.o=.d)
TESTS_DEPS_DEBUG		:= $(TESTS_OBJS_DEBUG:.o=.d)
TESTS_DEPS_SAN			:= $(TESTS_OBJS_SAN:.o=.d)

# ============================================================================ #
# Environment detection
# ============================================================================ #
DETECTED_OS				:= $(shell uname)
ifeq ($(DETECTED_OS),Darwin)
    DEBUGGER = lldb
    DEBUGGER_EXEC = lldb --
else
    DEBUGGER = gdb
    DEBUGGER_EXEC = gdb --args
endif

SANITIZE				:= $(shell $(C_COMPILER) -fsanitize=address -x c -c /dev/null -o /dev/null 2>/dev/null \
 							&& echo "-fsanitize=address -fsanitize=undefined" || echo "")

# ============================================================================ #
# Principal Rules
# ============================================================================ #
all: $(NAME)

$(NAME): $(RELEASE_OBJS)
	@printf "[\033[33mLINKING\033[0m]   %-35s\n" "$@"
	@$(AR) $(NAME) $(RELEASE_OBJS)

debug_lib: $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJS)
	@printf "[\033[33mLINKING\033[0m]   %-35s\n" "$@ (debug)"
	@$(AR) $(DEBUG_NAME) $(DEBUG_OBJS)

sanitize_lib: $(SANITIZED_NAME)

$(SANITIZED_NAME): $(SAN_OBJS)
	@printf "[\033[33mLINKING\033[0m]   %-35s\n" "$@ (ASan+UBSan)"
	@$(AR) $(SANITIZED_NAME) $(SAN_OBJS)

# ============================================================================ #
# Compilation rules (Pattern Rules)
# ============================================================================ #
# Compilation of C sources (library)
$(LIB_BUILD_RELEASE_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(MKDIR) $(@D)
	@printf "[\033[32mCOMPILING\033[0m] %-35s\n" "$< (release)"
	@$(C_COMPILER) $(C_FLAGS_RELEASE) -c $< -o $@

$(LIB_BUILD_DEBUG_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(MKDIR) $(@D)
	@printf "[\033[32mCOMPILING\033[0m] %-35s\n" "$< (debug)"
	@$(C_COMPILER) $(C_FLAGS_DEBUG) -c $< -o $@

$(LIB_BUILD_SAN_DIR)/%.o: $(SOURCE_DIR)/%.c
	@$(MKDIR) $(@D)
	@printf "[\033[32mCOMPILING\033[0m] %-35s\n" "$< (ASan+UBSan)"
	@$(C_COMPILER) $(C_FLAGS_SAN) -c $< -o $@

# Compilation of CXX sources (tests)
$(TESTS_BUILD_RELEASE_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@$(MKDIR) $(@D)
	@printf "[\033[34mCOMPILING\033[0m] %-35s\n" "$< (test release)"
	@$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -c $< -o $@

$(TESTS_BUILD_DEBUG_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@$(MKDIR) $(@D)
	@printf "[\033[34mCOMPILING\033[0m] %-35s\n" "$< (test debug)"
	@$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -c $< -o $@

$(TESTS_BUILD_SAN_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@$(MKDIR) $(@D)
	@printf "[\033[34mCOMPILING\033[0m] %-35s\n" "$< (test ASan+UBSan)"
	@$(CXX_COMPILER) $(CXX_FLAGS_SAN) -c $< -o $@

# ============================================================================ #
# Test rules
# ============================================================================ #
tests_build: $(NAME) $(TESTS_OBJS_RELEASE)
	@printf "[\033[33mLINKING\033[0m]   %-35s\n" "$(TESTS_BIN)"
	@$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $(TESTS_BIN) $(TESTS_OBJS_RELEASE) $(NAME) $(GTEST_FLAGS)

tests_run: tests_build
	@echo "Running tests..."
	@./$(TESTS_BIN)

tests_filter: tests_build
	@echo "Usage: make tests-filter FILTER=TestSuiteName*"
	@if [ -n "$(FILTER)" ]; then \
	   echo "Running tests matching: $(FILTER)"; \
	   ./$(TESTS_BIN) --gtest_filter="$(FILTER)"; \
	else \
	   echo "Please specify FILTER=pattern"; \
	   echo "Example: make tests-filter FILTER='*Strlen*'"; \
	fi

tests_debug: $(DEBUG_NAME) $(TESTS_OBJS_DEBUG)
	@printf "[\033[33mLINKING\033[0m]   %-35s\n" "$(TESTS_DEBUG) (debug)"
	@$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $(TESTS_DEBUG) $(TESTS_OBJS_DEBUG) $(DEBUG_NAME) $(GTEST_FLAGS)
	@echo "Debug tests ready. Run with: $(DEBUGGER_EXEC) ./$(TESTS_DEBUG)"

tests_sanitize: $(SANITIZED_NAME) $(TESTS_OBJS_SAN)
	@if [ -z "$(SANITIZE)" ]; then \
  		echo "Address sanitizer not supported on this system. Running regular tests."; \
  		$(MAKE) tests_debug; \
  else \
	   printf "[\033[33mLINKING\033[0m]   %-35s\n" "$(TESTS_SANITIZE) (ASan+UBSan)"; \
	   $(CXX_COMPILER) $(CXX_FLAGS_SAN) -o $(TESTS_SANITIZE) $(TESTS_OBJS_SAN) $(SANITIZED_NAME) $(GTEST_FLAGS); \
	   printf "[\033[34mSanitized tests ready\033[0m]. Run with: ./$(TESTS_SANITIZE)"; \
	fi

# ============================================================================ #
# Cleaning and utils Rules
# ============================================================================ #
clean:
	@printf "[\033[31mCLEANING\033[0m]  %-35s\n" "build directories"
	@$(RMD) $(BUILD_DIR)

fclean: clean
	@printf "[\033[31mCLEANING\033[0m]  %-35s\n" "executables"
	@$(RMF) $(NAME) $(DEBUG_NAME) $(SANITIZED_NAME) $(TESTS_BIN) $(TESTS_DEBUG) $(TESTS_SANITIZE)

re: fclean all

re_tests: fclean tests_build

# ============================================================================ #
# Help and debug rules
# ============================================================================ #
debug_vars:
	@echo "DETECTED_OS: $(DETECTED_OS)"
	@echo "SOURCE_DIR: $(SOURCE_DIR)"
	@echo "TESTS_DIR: $(TESTS_DIR)"
	@echo "SRCS: $(SRCS)"
	@echo "TESTS_SRCS: $(TESTS_SRCS)"
	@echo "RELEASE_OBJS: $(RELEASE_OBJS)"
	@echo "DEBUG_OBJS: $(DEBUG_OBJS)"
	@echo "SAN_OBJS: $(SAN_OBJS)"
	@echo "TESTS_OBJS_RELEASE: $(TESTS_OBJS_RELEASE)"
	@echo "TESTS_OBJS_DEBUG: $(TESTS_OBJS_DEBUG)"
	@echo "TESTS_OBJS_SAN: $(TESTS_OBJS_SAN)"
	@echo "SANITIZE: $(SANITIZE)"

norm:
	@echo "Checking 42 norm..."
	@norminette $$(find $(INCLUDE_DIR) -type f -name "*.h" 2>/dev/null) || true
	@norminette $$(find $(SOURCE_DIR) -type f -name "*.c" 2>/dev/null) || true

check_gtest:
	@echo "Checking GTest installation..."
	@pkg-config --exists gtest && echo "✓ GTest found" || echo "✗ GTest not found. Install with: sudo dnf install gtest-devel"
	@echo "GTest version: $$(pkg-config --modversion gtest 2>/dev/null || echo 'not found')"

info:
	@echo "┌─────────────────────────────────────────────────────────────┐"
	@printf "│%*s%*s│\n" 30 "Makefile for libft" 31 ""
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Library targets:"
	@printf "│   %-19s : %-35s │\n" "make" "compile the main library ($(NAME))"
	@printf "│   %-19s : %-35s │\n" "make debug_lib" "compile with debug symbols ($(DEBUGGER))"
	@printf "│   %-19s : %-35s │\n" "make sanitize_lib" "compile with address sanitizer"
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Test targets:"
	@printf "│   %-19s : %-35s │\n" "make tests_build" "only compile tests binary"
	@printf "│   %-19s : %-35s │\n" "make tests_run" "run existing tests binary"
	@printf "│   %-19s : %-35s │\n" "make tests_filter" "run filtered tests (FILTER=pattern)"
	@printf "│   %-19s : %-35s │\n" "make tests_debug" "compile tests with debug symbols"
	@printf "│   %-19s : %-35s │\n" "make tests_sanitize" "run sanitized tests"
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Utility targets:"
	@printf "│   %-19s : %-35s │\n" "make clean" "remove object files"
	@printf "│   %-19s : %-35s │\n" "make fclean" "remove objects, library and bins"
	@printf "│   %-19s : %-35s │\n" "make re" "execute fclean then all"
	@printf "│   %-19s : %-35s │\n" "make re_tests" "execute fclean then tests"
	@echo "├─────────────────────────────────────────────────────────────┤"
	@printf "│ %-59s │\n" "Help and debug targets:"
	@printf "│   %-19s : %-35s │\n" "make debug_vars" "show variables for debugging"
	@printf "│   %-19s : %-35s │\n" "make norm" "run norminette on source files"
	@printf "│   %-19s : %-35s │\n" "make check_gtest" "verify GTest installation"
	@echo "└─────────────────────────────────────────────────────────────┘"
	@printf "Tests directory: %s/ (*.cpp files)\n" "$(TESTS_DIR)"

# ============================================================================ #
# Phony and includes configuration
# ============================================================================ #
.PHONY: all debug_lib sanitize_lib \
        tests_build tests_run tests_filter \
      	tests_debug tests_sanitize \
        clean fclean re re_tests \
        debug_vars norm check_gtest info

-include $(RELEASE_DEPS) $(DEBUG_DEPS) $(SAN_DEPS) $(TESTS_DEPS_RELEASE) $(TESTS_DEPS_DEBUG) $(TESTS_DEPS_SAN)

# QoL
.SECONDARY: $(RELEASE_OBJS) $(DEBUG_OBJS) $(SAN_OBJS) $(TESTS_OBJS_RELEASE) $(TESTS_OBJS_DEBUG) $(TESTS_OBJS_SAN)
.SUFFIXES:
