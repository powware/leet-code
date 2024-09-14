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
            std::size_t pos;
        };

        std::deque<Occurence> occurences;
        std::optional<Interval> min;

        std::unordered_map<char, int> missing;

        std::array<bool, offset('z') + 1> t_mapped({});
        std::size_t total_missing = t.size();
        for (auto c : t)
        {
            t_mapped[offset(c)] = true;
            ++missing[c];
        }

        std::optional<std::size_t> first;
        std::size_t last;

        for (std::size_t i = 0; i < s.size(); ++i)
        {
            if (not t_mapped[offset(s[i])])
            {
                continue;
            }

            if (!first)
            {
                first = i;
            }

            if (missing[s[i]]-- > 0)
            {
                --total_missing;
            }

            occurences.emplace_back(s[i], i);

            if (total_missing)
            {
                continue;
            }

            last = i;
            auto size = last - *first + 1;
            if (not min or size < min->size)
            {
                min = {size, *first};
            }

            while (total_missing == 0)
            {
                auto occ = occurences.front();
                occurences.pop_front();

                if (occurences.size())
                {
                    first = occurences.front().i;
                }
                else
                {
                    first = std::nullopt;
                }

                if (++missing[occ.c] > 0)
                {
                    ++total_missing;
                }
                else if (first)
                {
                    auto size = last - *first + 1;
                    if (size < min->size)
                    {
                        min = {size, *first};
                    }
                }
            }
        }

        return min ? s.substr(min->pos, min->size) : "";
    }
};

void MinimumWindowSubstringCommon(std::string s, std::string t, std::string expected)
{
    Solution solution;
    ASSERT_EQ(solution.minWindow(s, t), expected);
}

TEST(MinimumWindowSubstring, Case0)
{
    MinimumWindowSubstringCommon("aaaaaaaaaaaabbbbbcdd", "abcdd", "abbbbbcdd");
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
