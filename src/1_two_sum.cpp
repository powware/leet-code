#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, std::size_t> visited;

        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            if (visited.find(target - nums[i]) != visited.end())
            {
                return {int(i), int(visited[target - nums[i]])};
            }

            visited[nums[i]] = i;
        }

        return {};
    }
};

void TwoSumCommon(vector<int> nums, int target, vector<int> expected)
{
    Solution solution;
    auto result = solution.twoSum(nums, target);

    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(result.size(), expected.size());
    ASSERT_TRUE((result[0] == expected[0] && result[1] == expected[1]) || (result[0] == expected[1] && result[1] == expected[0]));
}

TEST(TwoSum, Case1)
{
    TwoSumCommon({2, 7, 11, 15}, 9, {0, 1});
}

TEST(TwoSum, Case2)
{
    TwoSumCommon({3, 2, 4}, 6, {1, 2});
}

TEST(TwoSum, Case3)
{
    TwoSumCommon({3, 3}, 6, {0, 1});
}