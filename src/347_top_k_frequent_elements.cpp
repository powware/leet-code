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

        std::unordered_map<int, std::size_t> frequencies;
        std::map<std::size_t, std::vector<int>, std ::greater<std::size_t>> buckets;

        for (auto num : nums)
        {
            ++frequencies[num];
        }

        for (auto frequency : frequencies)
        {
            buckets[frequency.second].push_back(frequency.first);
        }

        std::vector<int> result;
        result.reserve(k);
        for (auto &bucket : buckets)
        {
            for (auto num : bucket.second)
            {
                result.push_back(num);
                if (result.size() == std::size_t(k))
                {
                    return result;
                }
            }
        }

        return {};
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
