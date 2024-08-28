#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    int climbStairs(int n)
    {
        std::vector<int> steps(n);
        steps[0] = 1;
        steps[1] = 2;

        for (int i = 3; i <= n; i++)
        {
            steps[i - 1] = steps[i - 2] + steps[i - 3];
        }

        return steps[n - 1];
    }
};

void ClimbingStairsCommon(int n, int e)
{
    Solution solution;

    ASSERT_EQ(solution.climbStairs(n), e);
}

TEST(ClimbingStairs, Case1)
{
    ClimbingStairsCommon(2, 2);
}

TEST(ClimbingStairs, Case2)
{
    ClimbingStairsCommon(3, 3);
}

TEST(ClimbingStairs, Case3)
{
    ClimbingStairsCommon(13, 377);
}