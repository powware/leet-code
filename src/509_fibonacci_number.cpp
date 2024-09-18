#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int fib(int n)
    {
        int nums[2] = {0, 1};
        if (n < 1)
        {
            return nums[n];
        }

        for (int i = 0; i < n - 1; ++i)
        {
            int num = nums[0] + nums[1];
            nums[0] = nums[1];
            nums[1] = num;
        }

        return nums[1];
    }
};

void FibonacciNumberCommon(int n, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.fib(n), expected);
}

TEST(FibonacciNumber, Case1)
{
    FibonacciNumberCommon(2, 1);
}

TEST(FibonacciNumber, Case2)
{
    FibonacciNumberCommon(3, 2);
}

TEST(FibonacciNumber, Case3)
{
    FibonacciNumberCommon(4, 3);
}