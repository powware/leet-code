#include <array>
#include <cmath>

#include <gtest/gtest.h>

class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        slow = nums[0];
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

void FindTheDuplicateNumberCommon(std::vector<int> nums, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.findDuplicate(nums), expected);
}

TEST(FindTheDuplicateNumber, Case1)
{
    FindTheDuplicateNumberCommon({1, 3, 4, 2, 2}, 2);
}

TEST(FindTheDuplicateNumber, Case2)
{
    FindTheDuplicateNumberCommon({3, 1, 3, 4, 2}, 3);
}

TEST(FindTheDuplicateNumber, Case3)
{
    FindTheDuplicateNumberCommon({3, 3, 3, 3, 3}, 3);
}
