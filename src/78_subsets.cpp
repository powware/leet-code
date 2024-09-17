#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        Recurse(result, nums, {}, 0, nums.size());
        return result;
    }

private:
    void Recurse(std::vector<std::vector<int>> &result, std::vector<int> &nums, std::vector<int> subset, const std::size_t start, const std::size_t n)
    {
        if (start == n)
        {
            result.push_back(std::move(subset));
            return;
        }

        Recurse(result, nums, subset, start + 1, n);
        subset.push_back(nums[start]);
        Recurse(result, nums, subset, start + 1, n);
    }
};

void SubsetsCommon(std::vector<int> nums)
{
    Solution solution;
    auto result = solution.Subsets(nums);
}

TEST(Subsets, Case1)
{
    SubsetsCommon({1, 2, 3});
}