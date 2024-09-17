#include <vector>
#include <queue>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        int minutes = 0;
        std::queue<std::tuple<int, std::size_t, std::size_t>> rot;
        std::size_t n = grid.size();
        std::size_t m = grid[0].size();
        std::size_t fresh = 0;
        for (std::size_t i = 0; i < n; ++i)
        {
            for (std::size_t j = 0; j < m; ++j)
            {
                int val = grid[i][j];
                if (val == 1)
                {
                    ++fresh;
                }
                else if (val == 2)
                {
                    rot.emplace(1, i, j);
                }
            }
        }

        while (fresh and not rot.empty())
        {
            auto [minute, rot_i, rot_j] = rot.front();
            rot.pop();
            auto next_minute = minute + 1;
            std::size_t offset = rot_j > 0 ? rot_j - 1 : 0;
            if (grid[rot_i][offset] == 1)
            {
                grid[rot_i][offset] = 2;
                rot.emplace(next_minute, rot_i, offset);
                minutes = minute;
                --fresh;
            }
            offset = rot_i > 0 ? rot_i - 1 : 0;
            if (grid[offset][rot_j] == 1)
            {
                grid[offset][rot_j] = 2;
                rot.emplace(next_minute, offset, rot_j);
                minutes = minute;
                --fresh;
            }
            offset = std::min(m - 1, rot_j + 1);
            if (grid[rot_i][offset] == 1)
            {
                grid[rot_i][offset] = 2;
                rot.emplace(next_minute, rot_i, offset);
                minutes = minute;
                --fresh;
            }
            offset = std::min(n - 1, rot_i + 1);
            if (grid[offset][rot_j] == 1)
            {
                grid[offset][rot_j] = 2;
                rot.emplace(next_minute, offset, rot_j);
                minutes = minute;
                --fresh;
            }
        }

        return fresh > 0 ? -1 : minutes;
    }
};

void RottingOrangesCommon(std::vector<std::vector<int>> grid, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.orangesRotting(grid), expected);
}

TEST(RottingOranges, Case1)
{
    RottingOrangesCommon({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
}

TEST(RottingOranges, Case2)
{
    RottingOrangesCommon({{0, 2}}, 0);
}

TEST(RottingOranges, Case3)
{
    RottingOrangesCommon({{0, 1}}, -1);
}
