#include <string>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        std::size_t front = 0;
        std::size_t back = height.size() - 1;
        int max = 0;
        do
        {
            int area = Area(height, front, back);
            if (area > max)
            {
                max = area;
            }

            if (height[front] < height[back])
            {
                ++front;
            }
            else
            {
                --back;
            }
        } while (back - front > 0);

        return max;
    }

private:
    inline int Area(std::vector<int> &height, int front, int back)
    {
        return (back - front) * std::min(height[front], height[back]);
    }
};

void ContainerWithMostWaterCommon(std::vector<int> heights, int expected)
{
    Solution solution;

    EXPECT_EQ(solution.maxArea(heights), expected);
}

TEST(ContainerWithMostWater, Case1)
{
    ContainerWithMostWaterCommon({1, 3, 1, 25, 1, 24, 5}, 24);
}

// TEST(ContainerWithMostWater, Case1)
// {
//     ContainerWithMostWaterCommon({1, 3, 2, 5, 25, 24, 5}, 24);
// }

TEST(ContainerWithMostWater, Case2)
{
    ContainerWithMostWaterCommon({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
}

TEST(ContainerWithMostWater, Case3)
{
    ContainerWithMostWaterCommon({1, 8}, 7);
}

TEST(ContainerWithMostWater, Case4)
{
    ContainerWithMostWaterCommon({2, 3, 4, 5, 18, 17, 6}, 17);
}
