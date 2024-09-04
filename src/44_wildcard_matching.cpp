#include <vector>
#include <iostream>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        std::size_t si = 0;
        std::size_t pi = 0;

        if (s.size() == 0)
        {
            for (auto c : p)
            {
                if (c != '*')
                {
                    return false;
                }
            }
            return true;
        }

        std::optional<std::tuple<std::size_t, std::size_t>> try_match_all_from;

        while (true)
        {
            if (p[pi] == '*')
            {
                while (p[pi] == '*')
                {
                    ++pi;
                    if (pi >= p.size())
                    {
                        return true;
                    }
                }

                try_match_all_from = {si, pi};
            }

            if (si >= s.size())
            {
                return false;
            }

            if (s[si] == p[pi] || p[pi] == '?')
            {
                ++si;
                ++pi;
            }
            else if (try_match_all_from)
            {
                si = ++std::get<0>(*try_match_all_from);
                pi = std::get<1>(*try_match_all_from);

                // if (si == s.size())
                // {
                //     return false;
                // }
            }
            else
            {
                return false;
            }

            if (pi >= p.size())
            {
                if (si == s.size())
                {
                    return true;
                }
                else if (try_match_all_from)
                {
                    si = ++std::get<0>(*try_match_all_from);
                    pi = std::get<1>(*try_match_all_from);

                    // if (si == s.size())
                    // {
                    //     return false;
                    // }
                }
                else
                {
                    return false;
                }
            }
        }
    }
};

void WildcardMatchingCommon(std::string s, std::string p, bool expected)
{
    Solution solution;

    ASSERT_EQ(solution.isMatch(s, p), expected);
}

TEST(WildcardMatching, Case1)
{
    WildcardMatchingCommon("aa", "a", false);
}

TEST(WildcardMatching, Case2)
{
    WildcardMatchingCommon("aa", "*", true);
}

TEST(WildcardMatching, Case3)
{
    WildcardMatchingCommon("cb", "?a", false);
}

TEST(WildcardMatching, Case4)
{
    WildcardMatchingCommon("cb", "?b", true);
}

TEST(WildcardMatching, Case6)
{
    WildcardMatchingCommon("sskiqwkeokll", "*ski*", true);
}

TEST(WildcardMatching, Case7)
{
    WildcardMatchingCommon("abbabaaaaabbaababbabbbbbabbbabbbabaaaaabababbcabbababababaabbababaabbbbbbaaabababbbaabbbbaabbbbabababaabbbbabbaababaabbbababababbbbbbaaabaabaaaabbababbbbaabaaabaaccbbababbbbbababbbaabbabaaaaaaaabbabbbaabaaababaaaabb", "*a**", true);
}

TEST(WildcardMatching, Case8)
{
    WildcardMatchingCommon("abcabczzzde", "*abc???de*", true);
}

TEST(WildcardMatching, Case9)
{
    WildcardMatchingCommon("mississippi", "m??*ss*?i*pi", false);
}

TEST(WildcardMatching, Case10)
{
    WildcardMatchingCommon("aaaa", "***a", true);
}

TEST(WildcardMatching, Case11)
{
    WildcardMatchingCommon("ho", "ho**", true);
}

TEST(WildcardMatching, Case12)
{
    WildcardMatchingCommon("abcabczzzde", "*abc???de*", true);
}

TEST(WildcardMatching, Case13)
{
    WildcardMatchingCommon("aa", "*", true);
}

TEST(WildcardMatching, Case14)
{
    WildcardMatchingCommon("b", "?*?", false);
}
