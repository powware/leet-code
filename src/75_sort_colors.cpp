#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        std::size_t r = 0;
        std::size_t w = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[r++]);

                if (w >= r)
                {
                    std::swap(nums[i], nums[w]);
                }
                ++w;
            }
            else if (nums[i] == 1)
            {
                std::swap(nums[i], nums[w++]);
            }
        }
    }
};

void SortColorsCommon(std::vector<int> nums)
{
    Solution solution;
    solution.sortColors(nums);
}

TEST(SortColors, Case1)
{
    SortColorsCommon({1, 2, 0});
}