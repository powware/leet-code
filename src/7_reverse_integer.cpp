#include <vector>
#include <string>
#include <limits>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (!x)
        {
            return 0;
        }

        int highest_power_of_ten = 9;
        int temp = x;
        int div = 10;
        for (int i = 1; i < 9; i++)
        {
            int mod = temp % div;
            if (mod)
            {
                temp -= mod;
                highest_power_of_ten = i;
                if (!temp)
                {
                    break;
                }
            }

            div *= 10;
        }

        int result = 0;
        int mul = div / 10;
        for (int i = 1, div2 = 10; i <= highest_power_of_ten; i++)
        {
            result += ((x % div2) / (div2 / 10)) * mul;
            div2 *= 10;
            mul /= 10;
        }

        return result;
    }
};

void ReverseIntegerCommon(int i, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.reverse(i), expected);
}

TEST(ReverseInteger, Case1)
{
    ReverseIntegerCommon(123, 321);
}

TEST(ReverseInteger, Case2)
{
    ReverseIntegerCommon(-123, -321);
}

TEST(ReverseInteger, Case3)
{
    ReverseIntegerCommon(120, 21);
}

TEST(ReverseInteger, Case4)
{
    ReverseIntegerCommon(0, 0);
}