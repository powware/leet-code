#include <vector>
#include <string>
#include <optional>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        std::optional<bool> negative;
        std::vector<int> digits;
        for (auto c : s)
        {
            if (c == ' ' && !negative)
            {
                continue;
            }
            int digit = c - '0';
            if (digit >= 0 && digit <= 9)
            {
                if (!negative)
                {
                    negative = false;
                }

                if (digits.size() == 0 && digit == 0)
                {
                    continue;
                }

                digits.push_back(digit);
            }
            else
            {
                if (negative)
                {
                    break;
                }

                if (c == '-')
                {
                    negative = true;
                }
                else if (c == '+')
                {
                    negative = false;
                }
                else
                {
                    break;
                }
            }
        }

        int64_t result = 0;
        if (!negative)
        {
            return 0;
        }

        for (auto digit : digits)
        {

            if (result < std::numeric_limits<int>::min() / 10)
            {
                return std::numeric_limits<int>::min();
            }
            else if (result > std::numeric_limits<int>::max() / 10)
            {
                return std::numeric_limits<int>::max();
            }

            result *= 10;

            if (*negative)
            {
                result -= digit;
            }
            else
            {
                result += digit;
            }
        }

        if (result < std::numeric_limits<int>::min())
        {
            return std::numeric_limits<int>::min();
        }
        else if (result > std::numeric_limits<int>::max())
        {
            return std::numeric_limits<int>::max();
        }

        return int(result);
    }
};

void StringToIntegerCommon(std::string s, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.myAtoi(s), expected);
}

// TEST(StringToInteger, Case1)
// {
//     StringToIntegerCommon("42", 42);
// }

// TEST(StringToInteger, Case2)
// {
//     StringToIntegerCommon("   -042", -42);
// }

// TEST(StringToInteger, Case3)
// {
//     StringToIntegerCommon("1337c0d3", 1337);
// }

// TEST(StringToInteger, Case4)
// {
//     StringToIntegerCommon("0-1", 0);
// }

// TEST(StringToInteger, Case5)
// {
//     StringToIntegerCommon("words and 987", 0);
// }

TEST(StringToInteger, Case6)
{
    StringToIntegerCommon("   +0 123", 0);
}