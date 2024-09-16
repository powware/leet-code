#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        struct Frequency
        {
            int num;
            std::size_t frequency;
        };
        std::priority_queue<Frequency, std::vector<Frequency>, decltype([](auto &lhs, auto &rhs)
                                                                        { return lhs.frequency < rhs.frequency; })>
            max;
        std::unordered_map<int, std::size_t> frequencies;

        for (auto num : nums)
        {
            ++frequencies[num];
        }

        for (auto frequency : frequencies)
        {
            max.push(Frequency(frequency.first, frequency.second));
        }

        std::vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i)
        {
            result.push_back(max.top().num);
            max.pop();
        }

        return result;
    }
};

void TopKFrequentElementsCommon(std::vector<int> nums, int k, std::vector<int> expected)
{
    Solution solution;
    auto result = solution.topKFrequent(nums, k);
    ASSERT_EQ(result.size(), expected.size());
    for (std::size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(TopKFrequentElements, Case1)
{
    TopKFrequentElementsCommon({1, 1, 1, 2, 2, 3}, 2, {1, 2});
}

TEST(TopKFrequentElements, Case2)
{
    TopKFrequentElementsCommon({5, 3, 1, 1, 1, 3, 73, 1}, 2, {1, 3});
}
