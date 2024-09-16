#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> findClosestElements(std::vector<int> &nums, int k, int x)
    {
        std::vector<int> result;
        result.reserve(k);

        std::size_t n = nums.size();

        std::size_t i = 0;
        for (; i < n and nums[i] <= x; ++i)
            ;

        if (i == 0)
        {
            result.insert(result.end(), nums.begin(), nums.begin() + k);
        }
        else if (i == n)
        {
            result.insert(result.end(), nums.rbegin(), nums.rbegin() + k);
        }

        std::optional<std::size_t> left = i - 1;
        std::optional<std::size_t> right = i;

        while (result.size() < std::size_t(k))
        {
            if (left and right)
            {
                if (std::abs(nums[*left] - x) <= std::abs(nums[*right] - x))
                {
                    result.push_back(nums[*left]);
                    if (*left == 0)
                    {
                        left = std::nullopt;
                    }
                    else
                    {
                        --(*left);
                    }
                }
                else
                {
                    result.push_back(nums[*right]);
                    if (*right == n - 1)
                    {
                        right = std::nullopt;
                    }
                    else
                    {
                        ++(*right);
                    }
                }
            }
            else if (left)
            {
                result.push_back(nums[(*left)--]);
            }
            else if (right)
            {
                result.push_back(nums[(*right)++]);
            }
        }

        std::sort(result.begin(), result.end());

        return result;
    }
};

void FindKClosestElementsCommon(std::vector<int> nums, int k, int x, std::vector<int> expected)
{
    Solution solution;
    auto result = solution.findClosestElements(nums, k, x);
    ASSERT_EQ(result.size(), expected.size());
    for (std::size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(FindKClosestElements, Case1)
{
    FindKClosestElementsCommon({0, 1, 2, 2, 2, 3, 6, 8, 8, 9}, 5, 9, {3, 6, 8, 8, 9});
}

TEST(FindKClosestElements, Case2)
{
    FindKClosestElementsCommon({-2, -1, 1, 2, 3, 4, 5}, 7, 3, {-2, -1, 1, 2, 3, 4, 5});
}

TEST(FindKClosestElements, Case3)
{
    FindKClosestElementsCommon({1, 2, 3, 4, 5}, 4, 3, {1, 2, 3, 4});
}
