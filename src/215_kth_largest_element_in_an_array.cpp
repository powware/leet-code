#include <vector>
#include <algorithm>
#include <queue>

#include <gtest/gtest.h>

class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>> heap;

        for (auto num : nums)
        {
            heap.push(num);
        }

        for (int i = 0; i < k - 1; ++i)
        {
            heap.pop();
        }

        return heap.top();
    }

private:
    // fails cause i didnt use rand
    // int quick_select(std::vector<int> &nums, std::size_t left, std::size_t right, int k)
    // {
    //     std::size_t pivot = partition(nums, left, right);

    //     if (pivot == std::size_t(k - 1))
    //     {
    //         return nums[pivot];
    //     }
    //     else if (pivot > std::size_t(k - 1))
    //     {
    //         return quick_select(nums, left, pivot - 1, k);
    //     }
    //     else
    //     {
    //         return quick_select(nums, pivot + 1, right, k);
    //     }
    // }

    // std::size_t partition(std::vector<int> &nums, std::size_t left, std::size_t right)
    // {
    //     for (std::size_t i = left; i < right; ++i)
    //     {
    //         int pivot = nums[right];
    //         if (nums[i] >= pivot)
    //         {
    //             std::swap(nums[left++], nums[i]);
    //         }
    //     }
    //     std::swap(nums[left], nums[right]);

    //     return left;
    // }
};

void KthLargestElementInAnArrayCommon(std::vector<int> nums, int k, int expected)
{
    Solution solution;
    ASSERT_EQ(solution.findKthLargest(nums, k), expected);
}

TEST(KthLargestElementInAnArray, Case0)
{
    KthLargestElementInAnArrayCommon({3, 2, 1, 5, 6, 4, 6, 5, 1, 4, 7, 2, 1, 2, 4, 6, 8, 2, 1, 4, 62, 1, 4, 5, 1, 1, 2, 5, 32, 2, 1, 5, 7, 211, 2, 4}, 2, 62);
}

TEST(KthLargestElementInAnArray, Case1)
{
    KthLargestElementInAnArrayCommon({3, 2, 1, 5, 6, 4}, 2, 5);
}

TEST(KthLargestElementInAnArray, Case2)
{
    KthLargestElementInAnArrayCommon({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4);
}
