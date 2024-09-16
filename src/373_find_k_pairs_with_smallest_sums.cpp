#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        struct Sum
        {
            std::pair<std::size_t, std::size_t> indexes;
            int sum;
        };

        std::size_t n = nums1.size();
        std::size_t m = nums2.size();
        std::priority_queue<Sum, std::vector<Sum>, decltype([](const Sum &lhs, const Sum &rhs)
                                                            { return lhs.sum > rhs.sum; })>
            min;

        std::vector<std::vector<int>> results;
        const auto push_sum = [&](std::size_t i, std::size_t j)
        { min.push({{i, j}, nums1[i] + nums2[j]}); };

        for (std::size_t i = 0; i < std::min<std::size_t>(n, k); ++i)
        {
            push_sum(i, 0);
        }

        while (results.size() < std::size_t(k))
        {
            auto [i, j] = min.top().indexes;
            min.pop();
            if (j < m - 1)
            {
                push_sum(i, j + 1);
            }

            results.push_back({nums1[i], nums2[j]});
        }

        return results;
    }
};

void FindKPairsWithSmallestSumsCommon(std::vector<int> nums1, std::vector<int> nums2, int k, std::vector<std::vector<int>> expected)
{
    Solution solution;
    auto results = solution.kSmallestPairs(nums1, nums2, k);
    ASSERT_EQ(results.size(), expected.size());
    for (std::size_t i = 0; i < results.size(); ++i)
    {
        ASSERT_EQ(results[i].size(), expected[i].size());

        for (std::size_t j = 0; j < results[i].size(); ++j)
        {
            ASSERT_EQ(results[i][j], expected[i][j]);
        }
    }
}

// TEST(FindKPairsWithSmallestSums, Case1)
// {
//     FindKPairsWithSmallestSumsCommon({1, 7, 11}, {2, 4, 6}, 3, {{1, 2}, {1, 4}, {1, 6}});
// }

// TEST(FindKPairsWithSmallestSums, Case2)
// {
//     FindKPairsWithSmallestSumsCommon({1, 1, 2}, {1, 2, 3}, 3, {{1, 1}, {1, 1}, {1, 2}});
// }

// TEST(FindKPairsWithSmallestSums, Case3)
// {
//     FindKPairsWithSmallestSumsCommon({1, 2, 4, 5, 6}, {3, 5, 7, 9}, 20, {{1, 3}, {2, 3}, {1, 5}, {2, 5}, {4, 3}, {1, 7}, {5, 3}, {2, 7}, {4, 5}, {6, 3}, {1, 9}, {5, 5}, {2, 9}, {4, 7}, {6, 5}, {5, 7}, {4, 9}, {6, 7}, {5, 9}, {6, 9}});
// }
