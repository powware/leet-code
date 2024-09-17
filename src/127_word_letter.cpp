#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

#include <gtest/gtest.h>

class Solution
{
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
    {
        std::queue<std::pair<std::string, int>> next;

        const auto n = wordList.size();
        const auto m = beginWord.size();

        next.emplace(std::move(beginWord), 0);

        while (not next.empty())
        {
            auto current = std::move(std::get<0>(next.front()));
            auto path = std::get<1>(next.front());
            next.pop();
            ++path;

            for (std::size_t i = 0; i < n; ++i)
            {
                if (wordList[i].empty())
                {
                    continue;
                }
                auto it = wordList[i];

                std::size_t differs = 0;
                for (std::size_t j = 0; j < m; ++j)
                {
                    if (current[j] != it[j])
                    {
                        ++differs;
                    }
                }
                if (differs == 1)
                {
                    if (it == endWord)
                    {
                        return path + 1;
                    }

                    next.emplace(std::move(it), path);
                    wordList[i].clear();
                }
            }
        }
        return 0;
    }
};

void WordLadderCommon(std::string beginWord, std::string endWord, std::vector<std::string> wordList, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.ladderLength(beginWord, endWord, wordList), expected);
}

TEST(WordLadder, Case1)
{
    WordLadderCommon("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
}

TEST(WordLadder, Case2)
{
    WordLadderCommon("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
}

TEST(WordLadder, Case3)
{
    WordLadderCommon("a", "c", {"a", "b", "c"}, 2);
}
