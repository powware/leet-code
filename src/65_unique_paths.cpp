#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<int> sub(m * n, 0);

        sub[0] = 1;

        for (std::size_t i = 0; i < m; i++)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                if (j + 1 < n)
                {
                    sub[i * n + j + 1] += sub[i * n + j];
                }

                if (i + 1 < m)
                {
                    sub[(i + 1) * n + j] += sub[i * n + j];
                }
            }
        }

        return sub[(m - 1) * n + n - 1];
    }
};

void UniquePathsCommon(int m, int n, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.uniquePaths(n, m), expected);
}

TEST(UniquePaths, Case1)
{
    UniquePathsCommon(1, 1, 1);
}

TEST(UniquePaths, Case2)
{
    UniquePathsCommon(3, 7, 28);
}

TEST(UniquePaths, Case3)
{
    UniquePathsCommon(3, 2, 3);
}