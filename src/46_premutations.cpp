#include <vector>
#include <unordered_set>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        n_ = nums.size();
        PermuteRecursively(result, nums, 0);
        return result;
    }

private:
    void PermuteRecursively(std::vector<std::vector<int>> &result, std::vector<int> &nums, std::size_t start)
    {
        if (start == n_)
        {
            result.push_back(nums);
        }
        for (std::size_t i = start; i < n_; ++i)
        {
            std::swap(nums[start], nums[i]);
            PermuteRecursively(result, nums, start + 1);
            std::swap(nums[start], nums[i]);
        }
    }

    std::size_t n_;
};

void InsertIntervalCommon(std::vector<int> nums)
{
    Solution solution;

    solution.permute(nums);
}

TEST(InsertInterval, Case0)
{
    InsertIntervalCommon({1, 2, 3});
}
