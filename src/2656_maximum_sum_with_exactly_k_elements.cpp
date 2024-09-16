#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
public:
    int maximizeSum(std::vector<int> &nums, int k)
    {
        std::optional<int> max;
        for (auto num : nums)
        {
            if (not max or num > *max)
            {
                max = num;
            }
        }

        return *max * k + (k * (k - 1)) / 2;
    }
};