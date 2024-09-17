#include <string>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string longest;
        for (std::size_t i = 0; i < s.size() - 1; ++i)
        {

            auto even = Palindrome(s, i, i + 1);
            if (even && even->size() > longest.size())
            {
                longest = *even;
            }

            if (i > 0)
            {
                auto uneven = Palindrome(s, i - 1, i + 1);
                if (uneven && uneven->size() > longest.size())
                {
                    longest = *uneven;
                }
            }
        }

        if (!longest.size())
        {
            return {s[0]};
        }

        return longest;
    }

private:
    std::optional<std::string> Palindrome(std::string s, std::size_t lhs, std::size_t rhs)
    {
        std::optional<std::tuple<std::size_t, std::size_t>> palindrome;
        do
        {
            if (s[lhs] != s[rhs])
            {
                break;
            }

            palindrome = {lhs, rhs};

        } while (lhs-- > 0 && rhs++ < s.size() - 1);

        return palindrome ? std::make_optional(s.substr(std::get<0>(*palindrome), std::get<1>(*palindrome) - std::get<0>(*palindrome) + 1)) : std::nullopt;
    }
};

void LongestPalindromicSubstringCommon(std::string s, std::string expected)
{
    Solution solution;

    EXPECT_EQ(solution.longestPalindrome(s), expected);
}

TEST(LongestPalindromicSubstring, Case1)
{
    LongestPalindromicSubstringCommon("babad", "bab");
}

TEST(LongestPalindromicSubstring, Case2)
{
    LongestPalindromicSubstringCommon("cbbd", "bb");
}

TEST(LongestPalindromicSubstring, Case3)
{
    LongestPalindromicSubstringCommon("abaxyzzyxf", "xyzzyx");
}

TEST(LongestPalindromicSubstring, Case4)
{
    LongestPalindromicSubstringCommon("forgeeksskeeg2or1283hnasdasdh9812h3ek12ne8asjdiasjdkl12j0e98j1290ejawsdjkasjmdkl2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd2j18ehjasndklansd12893hj1klnwdaklnsd812j4iqwkdnmaskldj12890jewajskdjaslkdj21890jeasnkldjn172g73gqasjhd", "geeksskeeg");
}

TEST(LongestPalindromicSubstring, Case5)
{
    LongestPalindromicSubstringCommon("abacdefghij", "aba");
}

TEST(LongestPalindromicSubstring, Case6)
{
    LongestPalindromicSubstringCommon("aabbcbbaa", "aabbcbbaa");
}
