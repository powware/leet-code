#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev_prev = 1;
        int prev = 2;
        int step = 0;

        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }

        for (int i = 3; i <= n; i++)
        {
            step = prev + prev_prev;
            prev_prev = prev;
            prev = step;
        }

        return step;
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