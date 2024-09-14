#include <algorithm>
#include <array>
#include <unordered_map>
#include <deque>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    static inline constexpr auto offset(char c)
    {
        return c - 'A';
    }

    std::string minWindow(std::string s, std::string t)
    {
        struct Occurence
        {
            char c;
            std::size_t i;
        };

        struct Interval
        {
            std::size_t size;
            std::size_t first;
            std::size_t last;
        };

        std::deque<Occurence> occurences;
        std::optional<Interval> min;

        std::unordered_map<char, std::size_t> missing;
        std::unordered_map<char, std::size_t> inside;

        std::array<bool, offset('z') + 1> t_mapped({});
        for (auto c : t)
        {
            t_mapped[offset(c)] = true;
            ++missing[c];
        }

        std::optional<std::size_t> first;
        std::size_t last;

        for (std::size_t i = 0; i < s.size(); ++i)
        {
            if (t_mapped[offset(s[i])])
            {
                if (!first)
                {
                    first = i;
                }

                ++inside[s[i]];
                auto it = missing.find(s[i]);
                if (it != missing.end())
                {
                    --it->second;
                    if (it->second == 0)
                    {
                        missing.erase(it);
                    }
                }

                occurences.emplace_back(s[i], i);
            }

            if (missing.size() == 0)
            {
                last = i;
                auto size = last - *first + 1;
                if (not min or size < min->size)
                {
                    min = {size, *first, last};
                }

                while (missing.size() == 0)
                {
                    auto occ = occurences.front();
                    occurences.pop_front();

                    if (not --inside[occ.c])
                    {
                        ++missing[occ.c];
                    }

                    if (occurences.size())
                    {
                        first = occurences.front().i;
                    }
                    else
                    {
                        first = std::nullopt;
                    }
                }
            }
        }

        return min ? s.substr(min->first, min->size) : "";
    }
};

void MinimumWindowSubstringCommon(std::string s, std::string t, std::string expected)
{
    Solution solution;
    ASSERT_EQ(solution.minWindow(s, t), expected);
}

TEST(MinimumWindowSubstring, Case1)
{
    MinimumWindowSubstringCommon("ADOBECODEBANC", "ABC", "BANC");
}

TEST(MinimumWindowSubstring, Case2)
{
    MinimumWindowSubstringCommon("a", "a", "a");
}

TEST(MinimumWindowSubstring, Case3)
{
    MinimumWindowSubstringCommon("a", "aa", "");
}

TEST(MinimumWindowSubstring, Case4)
{
    MinimumWindowSubstringCommon("aa", "aa", "aa");
}

TEST(MinimumWindowSubstring, Case5)
{
    MinimumWindowSubstringCommon("abc", "b", "b");
}

TEST(MinimumWindowSubstring, Case6)
{
    MinimumWindowSubstringCommon("bba", "ab", "ba");
}
