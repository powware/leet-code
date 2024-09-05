#include <vector>
#include <iostream>
#include <optional>

#include <gtest/gtest.h>

class NumArray
{
public:
    NumArray(std::vector<int> &nums)
    {
        prefix_sum_.reserve(nums.size());

        int sum = 0;
        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            prefix_sum_.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefix_sum_[right];
        }

        return prefix_sum_[right] - prefix_sum_[left - 1];
    }

private:
    std::vector<int> prefix_sum_;
};

void RangeSumQueryImmutableCommon(std::vector<int> nums, std::vector<std::vector<int>> ranges, std::vector<int> expected)
{
    NumArray num_array(nums);
    for (std::size_t i = 0; i < expected.size(); ++i)
    {
        ASSERT_EQ(num_array.sumRange(ranges[i][0], ranges[i][1]), expected[i]);
    }
}

TEST(RangeSumQueryImmutable, Case1)
{
    RangeSumQueryImmutableCommon({{-2, 0, 3, -5, 2, -1}}, {{0, 2}, {2, 5}, {0, 5}}, {1, -1, 3});
}