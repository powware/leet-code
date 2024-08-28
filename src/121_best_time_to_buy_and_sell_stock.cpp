#include <vector>
#include <optional>

#include <gtest/gtest.h>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int value = prices[0];
        int max_profit = 0;
        std::optional<int> day;
        for (std::size_t i = 1; i < prices.size(); ++i)
        {
            auto profit = prices[i] - value;
            if (profit < 0)
            {
                value = prices[i];
            }
            if (profit > max_profit)
            {
                max_profit = profit;
                day = i;
            }
        }

        return day ? *day + 1 : 0;
    }
};

void BestTimeToBuyAndSellStockCommon(std::vector<int> prices, int expected)
{
    Solution solution;

    ASSERT_EQ(solution.maxProfit(prices), expected);
}

// TEST(BestTimeToBuyAndSellStock, Case1)
// {
//     BestTimeToBuyAndSellStockCommon({7, 1, 5, 3, 6, 4}, 5);
// }

// TEST(BestTimeToBuyAndSellStock, Case2)
// {
//     BestTimeToBuyAndSellStockCommon({7, 6, 4, 3, 1}, 0);
// }

// TEST(BestTimeToBuyAndSellStock, Case3)
// {
//     BestTimeToBuyAndSellStockCommon({7, 6, 5, 4, 3, 7, 6, 5, 4, 3, 2, 1, 6, 5, 4, 3, 2, 8, 1, 2, 3, 4, 5, 6, 7}, 18);
// }

// TEST(BestTimeToBuyAndSellStock, Case4)
// {
//     BestTimeToBuyAndSellStockCommon({2, 7, 1, 4, 3, 1}, 2);
// }

TEST(BestTimeToBuyAndSellStock, Case5)
{
    BestTimeToBuyAndSellStockCommon({1, 2}, 1);
}