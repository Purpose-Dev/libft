#include <cstring>
#include <string>
#include <vector>

#include <gtest/gtest.h>

extern "C" {
#include "core/string/ft_string.h"
}

TEST(StrlenTest, HandlesBasicString)
{
	const char *s = "Hello, World!";
	EXPECT_EQ(ft_strlen(s), 13);
	EXPECT_EQ(ft_strlen(s), strlen(s));
}

TEST(StrlenTest, HandlesEmptyString)
{
	const char *s = "";
	EXPECT_EQ(ft_strlen(s), 0);
	EXPECT_EQ(ft_strlen(s), strlen(s));
}

TEST(StrlenTest, HandlesShortString)
{
	const char *s = "123";
	EXPECT_EQ(ft_strlen(s), 3);
}

TEST(StrlenTest, StopsAtFirstNull)
{
	constexpr char s[] = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'};
	EXPECT_EQ(ft_strlen(s), 5);
	EXPECT_EQ(ft_strlen(s), strlen(s));
}

TEST(StrlenTest, HandlesLongString)
{
	const std::string long_str(4096, 'a');
	const char		 *s = long_str.c_str();
	EXPECT_EQ(ft_strlen(s), 4096);
	EXPECT_EQ(ft_strlen(s), strlen(s));
}

TEST(StrlenTest, HandlesPageBoundary)
{
	constexpr size_t page_size = 4096;
	char			*data = static_cast<char *>(malloc(page_size * 2));
	char			*s = data + page_size - 4;
	s[0] = 'a';
	s[1] = 'b';
	s[2] = 'c';
	s[3] = '\0';
	EXPECT_EQ(ft_strlen(s), 3);
	free(data);
}
