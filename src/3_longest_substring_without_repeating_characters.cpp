#include <string>
#include <optional>
#include <iostream>
#include <array>
#include <limits>

#include <gtest/gtest.h>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int longest = 0;
        for (std::size_t i = 0; i < s.size(); ++i)
        {
            std::array<std::optional<std::size_t>, std::numeric_limits<std::string::value_type>::max()> current_chars;
            std::size_t j;
            for (j = i; j < s.size(); ++j)
            {
                if (current_chars[s[j]])
                {
                    if (j - i > longest)
                    {
                        longest = j - i;
                    }
                    i = *current_chars[s[j]];
                    break;
                }

                current_chars[s[j]] = j;
            }

            if (j == s.size() && j - i > longest)
            {
                longest = j - i;
            }
        }

        return longest;
    }
};

void LongestSubstringWithoutRepeatingCharactersCommon(std::string s, int expected)
{
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring(s), expected);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Case1)
{
    LongestSubstringWithoutRepeatingCharactersCommon("abcabcbb", 3);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Case2)
{
    LongestSubstringWithoutRepeatingCharactersCommon("bbbbb", 1);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Case3)
{
    LongestSubstringWithoutRepeatingCharactersCommon("pwwkew", 3);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Case4)
{
    LongestSubstringWithoutRepeatingCharactersCommon(" ", 1);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Case5)
{
    LongestSubstringWithoutRepeatingCharactersCommon("ab", 2);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Case6)
{
    LongestSubstringWithoutRepeatingCharactersCommon("dvdf", 3);
}