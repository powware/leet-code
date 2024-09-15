#include <vector>
#include <unordered_map>
#include <stack>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> next_greater;
        std::stack<int> mono;
        for (std::size_t i = nums2.size(); i-- > 0;)
        {
            int num = nums2[i];
            while (not mono.empty() && num >= mono.top())
            {
                mono.pop();
            }

            next_greater[num] = mono.empty() ? -1 : mono.top();
            mono.push(num);
        }

        std::vector<int> result;
        for (size_t i = 0; i < nums1.size(); ++i)
        {
            result.push_back(next_greater[nums1[i]]);
        }

        return result;
    }
};

void NextGreaterElement1Common(std::vector<int> nums1, std::vector<int> nums2, std::vector<int> expected)
{
    Solution solution;
    auto result = solution.nextGreaterElement(nums1, nums2);
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(NextGreaterElement1, Case1)
{
    NextGreaterElement1Common({4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1});
}
