#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <numeric>

#include <gtest/gtest.h>

class Solution
{
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
    {
        std::queue<std::pair<std::size_t, int>> next;
        std::unordered_set<std::size_t> set;
        const auto n = wordList.size();
        const auto m = beginWord.size();

        for (std::size_t i = 0; i < n; ++i)
        {
            set.emplace(i);
            std::size_t differs = 0;
            for (std::size_t j = 0; j < m; ++j)
            {
                if (beginWord[j] != wordList[i][j])
                {
                    ++differs;
                }
            }
            if (differs == 0)
            {
                next.emplace(i, 0);
            }
            else if (differs == 1)
            {
                if (wordList[i] == endWord)
                {
                    return 2;
                }
                next.emplace(i, 1);
            }
        }

        while (not next.empty())
        {
            auto [index, path] = next.front();
            next.pop();
            ++path;

            std::vector<std::size_t> remove;
            for (auto it = set.begin(); it != set.end();)
            {

                std::size_t differs = 0;
                for (std::size_t j = 0; j < m; ++j)
                {
                    if (wordList[index][j] != wordList[*it][j])
                    {
                        ++differs;
                    }
                }
                if (differs == 1)
                {
                    if (wordList[*it] == endWord)
                    {
                        return path + 1;
                    }

                    next.emplace(*it, path);
                    remove.push_back(*it);
                    it = set.erase(it);
                }
                else
                {
                    ++it;
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

// TEST(WordLadder, Case1)
// {
//     WordLadderCommon("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
// }

// TEST(WordLadder, Case2)
// {
//     WordLadderCommon("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
// }

// TEST(WordLadder, Case3)
// {
//     WordLadderCommon("a", "c", {"a", "b", "c"}, 2);
// }

// TEST(WordLadder, Case4)
// {
//     WordLadderCommon("hot", "dog", {"hot", "dog"}, 0);
// }

TEST(WordLadder, Case5)
{
    WordLadderCommon("lost", "cost", {"most", "fist", "lost", "cost", "fish"}, 2);
}
