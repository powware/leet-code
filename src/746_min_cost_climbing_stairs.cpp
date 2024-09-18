#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        const auto n = cost.size();
        for (std::size_t i = 2; i < n; ++i)
        {
            cost[i] += std::min(cost[i - 1], cost[i - 2]);
        }

        return std::min(cost[n - 1], cost[n - 2]);
    }
};

void MinCostClimbingStairsCommon(std::vector<int> cost, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.minCostClimbingStairs(cost), expected);
}

TEST(MinCostClimbingStairs, Case1)
{
    MinCostClimbingStairsCommon({10, 15, 20}, 15);
}

TEST(MinCostClimbingStairs, Case2)
{
    MinCostClimbingStairsCommon({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6);
}
