cmake_minimum_required(VERSION 3.16)
project(libft VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_COMPILER "cc")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(DEBUGGER "lldb")
    set(DEBUGGER_EXEC "lldb --")
else()
    set(DEBUGGER "gdb")
    set(DEBUGGER_EXEC "gdb --args")
endif()

set(LIBFT_COMPILE_FLAGS
        -Wall
        -Wextra
        -Werror
        -std=c99
        -pedantic
        -Wshadow
        -Wconversion
        -Wstrict-prototypes
        -Wmissing-prototypes
        -Wmissing-declarations
        -Wold-style-definition
)

set(LIBFT_DEBUG_FLAGS
        -g3
        -O0
        -DDEBUG
)

set(CMAKE_BUILD_TYPE_OPTIONS "Debug;Release;Sanitize")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_BUILD_TYPE_OPTIONS})
endif()

set(SRCS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/srcs")
set(INCS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")

set(LIBFT_SOURCES
        ${SRCS_DIR}/ft_atoi.c
        ${SRCS_DIR}/ft_bzero.c
        ${SRCS_DIR}/ft_calloc.c
        ${SRCS_DIR}/ft_isalnum.c
        ${SRCS_DIR}/ft_isalpha.c
        ${SRCS_DIR}/ft_isascii.c
        ${SRCS_DIR}/ft_isdigit.c
        ${SRCS_DIR}/ft_isprint.c
        ${SRCS_DIR}/ft_itoa.c
        ${SRCS_DIR}/ft_memchr.c
        ${SRCS_DIR}/ft_memcmp.c
        ${SRCS_DIR}/ft_memcpy.c
        ${SRCS_DIR}/ft_memmove.c
        ${SRCS_DIR}/ft_memset.c
        ${SRCS_DIR}/ft_putchar_fd.c
        ${SRCS_DIR}/ft_putendl_fd.c
        ${SRCS_DIR}/ft_putnbr_fd.c
        ${SRCS_DIR}/ft_putstr_fd.c
        ${SRCS_DIR}/ft_split.c
        ${SRCS_DIR}/ft_strchr.c
        ${SRCS_DIR}/ft_strdup.c
        ${SRCS_DIR}/ft_striteri.c
        ${SRCS_DIR}/ft_strjoin.c
        ${SRCS_DIR}/ft_strlcat.c
        ${SRCS_DIR}/ft_strlcpy.c
        ${SRCS_DIR}/ft_strlen.c
        ${SRCS_DIR}/ft_strmapi.c
        ${SRCS_DIR}/ft_strncmp.c
        ${SRCS_DIR}/ft_strnstr.c
        ${SRCS_DIR}/ft_strrchr.c
        ${SRCS_DIR}/ft_strtrim.c
        ${SRCS_DIR}/ft_substr.c
        ${SRCS_DIR}/ft_tolower.c
        ${SRCS_DIR}/ft_toupper.c
        ${SRCS_DIR}/ft_lstadd_back.c
        ${SRCS_DIR}/ft_lstadd_front.c
        ${SRCS_DIR}/ft_lstclear.c
        ${SRCS_DIR}/ft_lstdelone.c
        ${SRCS_DIR}/ft_lstiter.c
        ${SRCS_DIR}/ft_lstlast.c
        ${SRCS_DIR}/ft_lstmap.c
        ${SRCS_DIR}/ft_lstnew.c
        ${SRCS_DIR}/ft_lstsize.c
)


add_library(ft STATIC ${LIBFT_SOURCES})

target_include_directories(ft PUBLIC ${INCS_DIR})

target_compile_options(ft PRIVATE ${LIBFT_COMPILE_FLAGS})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(ft PRIVATE ${LIBFT_DEBUG_FLAGS})
    if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        target_compile_options(ft PRIVATE -g)
    else()
        target_compile_options(ft PRIVATE -ggdb)
    endif()
    message(STATUS "✓ Debug build configured for ${DEBUGGER}")
    message(STATUS "➤ Run your program with: ${DEBUGGER_EXEC} ./your_program")
elseif(CMAKE_BUILD_TYPE STREQUAL "Sanitize")
    include(CheckCCompilerFlag)
    check_c_compiler_flag("-fsanitize=address" HAVE_ASAN)
    check_c_compiler_flag("-fsanitize=undefined" HAVE_UBSAN)

    if(HAVE_ASAN AND HAVE_UBSAN)
        target_compile_options(ft PRIVATE -fsanitize=address -fsanitize=undefined)
        target_link_options(ft PRIVATE -fsanitize=address -fsanitize=undefined)
        message(STATUS "✓ Address Sanitizer build configured")
    else()
        message(WARNING "⚠️ Address sanitizer not supported on this system")
    endif()
endif()

add_library(libft ALIAS ft)

install(TARGETS ft
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY ${INCS_DIR}/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")

add_custom_target(info
        COMMAND ${CMAKE_COMMAND} -E echo "┌───────────────────────────────────────────────────────┐"
        COMMAND ${CMAKE_COMMAND} -E echo "│             CMakeLists.txt for libft                  │"
        COMMAND ${CMAKE_COMMAND} -E echo "├───────────────────────────────────────────────────────┤"
        COMMAND ${CMAKE_COMMAND} -E echo "│ cmake --build build          : compile the library    │"
        COMMAND ${CMAKE_COMMAND} -E echo "│ cmake -DCMAKE_BUILD_TYPE=Debug: compile with debug    │"
        COMMAND ${CMAKE_COMMAND} -E echo "│ cmake -DCMAKE_BUILD_TYPE=Sanitize: compile with ASAN  │"
        COMMAND ${CMAKE_COMMAND} -E echo "│ cmake --build build --target clean: remove objects    │"
        COMMAND ${CMAKE_COMMAND} -E echo "│ rm -rf build                  : clean everything      │"
        COMMAND ${CMAKE_COMMAND} -E echo "└───────────────────────────────────────────────────────┘"
)

message(STATUS "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━")
message(STATUS "  Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "  Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C Standard: C${CMAKE_C_STANDARD}")
message(STATUS "  Sources directory: ${SRCS_DIR}")
message(STATUS "  Headers directory: ${INCS_DIR}")
message(STATUS "  Total source files: ${CMAKE_CURRENT_LIST_DIR}")
list(LENGTH LIBFT_SOURCES TOTAL_FILES)
message(STATUS "  Total source files: ${TOTAL_FILES}")
message(STATUS "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━")
