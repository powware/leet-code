#include <vector>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        std::size_t row = 0;
        bool down = true;
        std::vector<std::string> rows(numRows);
        for (auto c : s)
        {
            rows[row].push_back(c);
            if (numRows == 1)
            {
                continue;
            }

            if (down)
            {
                if (row < numRows - 1)
                {
                    ++row;
                }
                else
                {
                    --row;
                    down = false;
                }
            }
            else
            {
                if (row > 0)
                {
                    --row;
                }
                else
                {
                    ++row;
                    down = true;
                }
            }
        }

        std::string result;
        for (auto row : rows)
        {
            result += row;
        }

        return result;
    }
};

void ZigzagConversionCommon(string s, int numRows, string expected)
{
    Solution solution;

    ASSERT_EQ(solution.convert(s, numRows), expected);
}

// TEST(ZigzagConversion, Case1)
// {
//     ZigzagConversionCommon("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
// }

// TEST(ZigzagConversion, Case2)
// {
//     ZigzagConversionCommon("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
// }

// TEST(ZigzagConversion, Case3)
// {
//     ZigzagConversionCommon("A", 1, "A");
// }

TEST(ZigzagConversion, Case4)
{
    ZigzagConversionCommon("AB", 1, "AB");
}