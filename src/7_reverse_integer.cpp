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
        int mod = 10;
        int result = 0;
        while (x)
        {
            if (result > std::numeric_limits<int>::max() / 10 || result < std::numeric_limits<int>::min() / 10)
            {
                return 0;
            }

            result *= 10;
            result += x % mod;
            x /= 10;
        }

        return result;
    }
};

void ReverseIntegerCommon(int i, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.reverse(i), expected);
}

// TEST(ReverseInteger, Case1)
// {
//     ReverseIntegerCommon(123, 321);
// }

// TEST(ReverseInteger, Case2)
// {
//     ReverseIntegerCommon(-123, -321);
// }

// TEST(ReverseInteger, Case3)
// {
//     ReverseIntegerCommon(120, 21);
// }

// TEST(ReverseInteger, Case4)
// {
//     ReverseIntegerCommon(0, 0);
// }

TEST(ReverseInteger, Case5)
{
    ReverseIntegerCommon(-2147483412, -2143847412);
}