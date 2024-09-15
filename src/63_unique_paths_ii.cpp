#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        std::size_t m = obstacleGrid.size();
        std::size_t n = obstacleGrid[0].size();

        if (obstacleGrid[0][0])
        {
            return 0;
        }

        obstacleGrid[0][0] = -1;

        for (std::size_t i = 0; i < m; i++)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    continue;
                }

                if (j + 1 < n && obstacleGrid[i][j + 1] != 1)
                {
                    obstacleGrid[i][j + 1] += obstacleGrid[i][j];
                }

                if (i + 1 < m && obstacleGrid[i + 1][j] != 1)
                {
                    obstacleGrid[i + 1][j] += obstacleGrid[i][j];
                }
            }
        }

        return obstacleGrid[m - 1][n - 1] == 1 ? 0 : obstacleGrid[m - 1][n - 1] * -1;
    }
};

void UniquePaths2Common(std::vector<std::vector<int>> obstacleGrid, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.uniquePathsWithObstacles(obstacleGrid), expected);
}

TEST(UniquePaths2, Case1)
{
    UniquePaths2Common({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2);
}

TEST(UniquePaths2, Case2)
{
    UniquePaths2Common({{0, 1}, {0, 0}}, 1);
}
