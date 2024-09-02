#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> results;

        std::sort(nums.begin(), nums.end(), std::less<>());

        for (std::size_t i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            std::size_t l = i + 1;
            std::size_t r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    results.push_back({nums[i], nums[l], nums[r]});
                    do
                    {
                        ++l;
                    } while (nums[l] == nums[l - 1] && l < r);
                    do
                    {
                        --r;
                    } while (nums[r] == nums[r + 1] && l < r);
                }
                else if (sum < 0)
                {
                    do
                    {
                        ++l;
                    } while (nums[l] == nums[l - 1] && l < r);
                }
                else
                {
                    do
                    {
                        --r;
                    } while (nums[r] == nums[r + 1] && l < r);
                }
            }
        }

        return results;
    }
};

void TwoSumCommon(std::vector<int> nums)
{
    Solution solution;
    auto result = solution.threeSum(nums);
}

TEST(ThreeSum, Case1)
{
    TwoSumCommon({0, 0, 0, 0});
}
