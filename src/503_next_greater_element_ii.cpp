#include <vector>
#include <unordered_map>
#include <stack>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    std::vector<int> nextGreaterElements(std::vector<int> &nums)
    {
        std::vector<int> result(nums.size(), -1);
        std::stack<int> mono;
        std::size_t i = nums.size() - 1;
        std::size_t passes = 2;
        std::size_t pass = 0;
        while (pass < passes)
        {
            int num = nums[i];
            while (not mono.empty() && num >= mono.top())
            {
                mono.pop();
            }

            if (mono.size())
            {
                result[i] = mono.top();
            }

            mono.push(num);

            if (i == 0)
            {
                i = nums.size() - 1;
                ++pass;
            }
            else
            {
                --i;
            }
        }

        return result;
    }
};

void NextGreaterElement2Common(std::vector<int> nums, std::vector<int> expected)
{
    Solution solution;
    auto result = solution.nextGreaterElements(nums);
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(NextGreaterElement2, Case1)
{
    NextGreaterElement2Common({1, 2, 1}, {2, -1, 2});
}

TEST(NextGreaterElement2, Case2)
{
    NextGreaterElement2Common({1, 2, 3, 4, 3}, {2, 3, 4, -1, 4});
}

TEST(NextGreaterElement2, Case3)
{
    NextGreaterElement2Common({1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1});
}

TEST(NextGreaterElement2, Case4)
{
    NextGreaterElement2Common({4, 1, 1, 1, 1}, {-1, 4, 4, 4, 4});
}

TEST(NextGreaterElement2, Case5)
{
    NextGreaterElement2Common({5, 4, 3, 2, 1}, {-1, 5, 5, 5, 5});
}
