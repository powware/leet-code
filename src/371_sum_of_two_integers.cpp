#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    int getSum(int a, int b)
    {
        int c = (a & b);
        int r = (a ^ b);

        while (c)
        {
            int t = r ^ (c << 1);
            c = r & (c << 1);
            r = t;
        }

        return r;
    }
};

void SumOfTwoIntegersCommon(int lhs, int rhs)
{
    Solution solution;

    ASSERT_EQ(solution.getSum(lhs, rhs), lhs + rhs);
}

TEST(SumOfTwoIntegers, Case1)
{
    SumOfTwoIntegersCommon(1, 2);
}

TEST(SumOfTwoIntegers, Case2)
{
    SumOfTwoIntegersCommon(2, 3);
}

TEST(SumOfTwoIntegers, Case3)
{
    SumOfTwoIntegersCommon(236, -233);
}

TEST(SumOfTwoIntegers, Case4)
{
    SumOfTwoIntegersCommon(-642, 0);
}

TEST(SumOfTwoIntegers, Case5)
{
    SumOfTwoIntegersCommon(22, 123);
}