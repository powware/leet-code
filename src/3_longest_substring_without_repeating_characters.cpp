#include <string>
#include <unordered_map>
#include <optional>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        optional<char> repeat_offender{};
        string longest;
        for (auto it = s.begin(); it != s.end(); ++it)
        {

            auto future = it;
            ++future;
            if (repeat_offender && future != s.end() && *repeat_offender == *future)
            {
                cout << "skipping " << *it << endl;
                continue;
            }

            string current;
            unordered_map<char, bool> current_chars;
            auto prev = it;
            for (auto sub_it = it; sub_it != s.end(); ++sub_it)
            {
                if (current_chars.find(*sub_it) == current_chars.end())
                {
                    current.append(string(1, *sub_it));
                    current_chars[*sub_it] = true;
                    prev = sub_it;
                }
                else
                {
                    repeat_offender = *sub_it;
                    it = prev;
                    if (current.size() > longest.size())
                    {
                        longest = std::move(current);
                    }

                    break;
                }
            }
        }

        cout << longest << endl;
        return longest.size();
    }
};

void LongestSubstringWithoutRepeatingCharactersCommon(string s, int expected)
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