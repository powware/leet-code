#include <unordered_map>
#include <iostream>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    int findMaxLength(std::vector<int> &nums)
    {
        int sum = 0;
        int max = 0;
        appearances_[0] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                --sum;
            }
            else
            {
                ++sum;
            }

            if (appearances_.find(sum) == appearances_.end())
            {
                appearances_[sum] = i;
            }
            else
            {
                int distance = i - appearances_[sum];
                if (distance > max)
                {
                    max = distance;
                }
            }
        }

        return max;
    }

private:
    std::unordered_map<int, int> appearances_;
};

void ContiguousArrayCommon(std::vector<int> nums, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.findMaxLength(nums), expected);
}

TEST(ContiguousArray, Case1)
{
    ContiguousArrayCommon({0, 1}, 2);
}

TEST(ContiguousArray, Case2)
{
    ContiguousArrayCommon({0, 1, 0}, 2);
}

TEST(ContiguousArray, Case3)
{
    ContiguousArrayCommon({1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1}, 10);
}

TEST(ContiguousArray, Case4)
{
    ContiguousArrayCommon({0, 1, 0, 1}, 4);
}