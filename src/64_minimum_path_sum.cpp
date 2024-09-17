#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

#include <gtest/gtest.h>

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        std::size_t m = grid.size();
        std::size_t n = grid[0].size();
        auto minis = std::vector<std::vector<int>>(m, std::vector<int>(n));
        for (std::size_t i = 0; i < m; ++i)
        {
            for (std::size_t j = 0; j < n; ++j)
            {
                int path = 0;
                if (i > 0 or j > 0)
                {
                    path = std::min((i > 0 ? minis[i - 1][j] : std::numeric_limits<int>::max()), (j > 0 ? minis[i][j - 1] : std::numeric_limits<int>::max()));
                }

                minis[i][j] = grid[i][j] + path;
            }
        }
        return minis[m - 1][n - 1];
    }
};

void MinimumPathSumCommon(std::vector<std::vector<int>> grid, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.minPathSum(grid), expected);
}

TEST(MinimumPathSum, Case1)
{
    MinimumPathSumCommon({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7);
}
