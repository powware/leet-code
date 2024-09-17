#include <vector>
#include <stack>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        struct Day
        {
            int i;
            int temp;
        };

        std::stack<Day> mono;
        std::vector<int> result(temperatures.size(), 0);

        for (size_t i = temperatures.size(); i-- > 0;)
        {
            int temp = temperatures[i];
            while (not mono.empty() and temp >= mono.top().temp)
            {
                mono.pop();
            }

            if (mono.size())
            {
                result[i] = mono.top().i - i;
            }

            mono.emplace(i, temp);
        }

        return result;
    }
};

void DailyTemperaturesCommon(std::vector<int> nums, std::vector<int> expected)
{
    Solution solution;
    auto result = solution.dailyTemperatures(nums);
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(DailyTemperatures, Case1)
{
    DailyTemperaturesCommon({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
}

TEST(DailyTemperatures, Case2)
{
    DailyTemperaturesCommon({30, 40, 50, 60}, {1, 1, 1, 0});
}

TEST(DailyTemperatures, Case3)
{
    DailyTemperaturesCommon({30, 60, 90}, {1, 1, 0});
}
