#include <array>
#include <cmath>

#include <gtest/gtest.h>

class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        while (fast != 1)
        {
            slow = SumDigitsSquared(slow);
            fast = SumDigitsSquared(fast);
            if (fast == 1)
            {
                return true;
            }

            fast = SumDigitsSquared(fast);
            if (fast == slow)
            {
                return false;
            }
        }

        return true;
    }

private:
    static inline int SumDigitsSquared(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += std::pow(n % 10, 2);
            n /= 10;
        }

        return sum;
    }
};

void HappyNumberCommon(int n, bool expected)
{
    Solution solution;

    ASSERT_EQ(solution.isHappy(n), expected);
}

TEST(HappyNumber, Case0)
{
    HappyNumberCommon(7, true);
}

TEST(HappyNumber, Case5)
{
    HappyNumberCommon(192352347, false);
}

TEST(HappyNumber, Case1)
{
    HappyNumberCommon(19, true);
}

TEST(HappyNumber, Case2)
{
    HappyNumberCommon(2, false);
}
