/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:34:41 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/17 22:40:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <gtest/gtest.h>

extern "C" {
#include "core/string/ft_string.h"
}

static int get_sign(int n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

TEST(StrncmpTest, HandlesIdenticalStrings) {
    const char *s = "Hello, World!";
    EXPECT_EQ(ft_strncmp(s, s, 15), 0);
    EXPECT_EQ(get_sign(ft_strncmp(s, s, 15)), get_sign(strncmp(s, s, 15)));
}

TEST(StrncmpTest, HandlesDifferentStrings) {
    const char *s1 = "Hello, world!";
    const char *s2 = "Hello, World!";
    EXPECT_GT(ft_strncmp(s1, s2, 15), 0);
    EXPECT_EQ(get_sign(ft_strncmp(s1, s2, 15)), get_sign(strncmp(s1, s2, 15)));
}

TEST(StrncmpTest, StopsComparisonAtN) {
    const char *s1 = "ABCDEF";
    const char *s2 = "ABCabc";
    EXPECT_EQ(ft_strncmp(s1, s2, 3), 0);
    EXPECT_EQ(get_sign(ft_strncmp(s1, s2, 3)), get_sign(strncmp(s1, s2, 3)));
}

TEST(StrncmpTest, HandlesNIsZero) {
    const char *s1 = "Non-empty";
    const char *s2 = "";
    EXPECT_EQ(ft_strncmp(s1, s2, 0), 0);
    EXPECT_EQ(strncmp(s1, s2, 0), 0);
}

TEST(StrncmpTest, HandlesPrefixStrings) {
    const char *s1 = "test";
    const char *s2 = "testing";
    EXPECT_LT(ft_strncmp(s1, s2, 10), 0);
    EXPECT_EQ(get_sign(ft_strncmp(s1, s2, 10)), get_sign(strncmp(s1, s2, 10)));
}

TEST(StrncmpTest, HandlesUnsignedCharactersCorrectly) {
    const char *s1 = "\200"; // 128
    const char *s2 = "\0";   // 0
    EXPECT_GT(ft_strncmp(s1, s2, 1), 0);
    EXPECT_EQ(get_sign(ft_strncmp(s1, s2, 1)), get_sign(strncmp(s1, s2, 1)));
}

TEST(StrncmpTest, HandlesEmptyStrings) {
    const char *s1 = "";
    const char *s2 = "";
    EXPECT_EQ(ft_strncmp(s1, s2, 5), 0);
    EXPECT_EQ(strncmp(s1, s2, 5), 0);
}

TEST(StrncmpTest, StopsAtEmbeddedNull) {
    const char s1[] = "test\0A";
    const char s2[] = "test\0B";
    EXPECT_EQ(ft_strncmp(s1, s2, 10), 0);
    EXPECT_EQ(strncmp(s1, s2, 10), 0);
}
