#include <vector>
#include <iostream>
#include <optional>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string> &products, std::string searchWord)
    {
        std::vector<std::vector<std::string>> results(searchWord.size());

        std::sort(products.begin(), products.end());

        std::size_t left = 0;

        for (std::size_t i = 0; i < searchWord.size(); ++i)
        {
            for (std::size_t l = left; l < products.size(); ++l)
            {
                if (products[l].starts_with({searchWord.begin(), searchWord.begin() + i + 1}))
                {
                    left = l;
                    std::size_t right = left + 1;
                    for (std::size_t r = right; r < left + 3 && r < products.size(); ++r)
                    {
                        if (products[r].starts_with({searchWord.begin(), searchWord.begin() + i + 1}))
                        {
                            ++right;
                        }
                    }
                    results[i].insert(results[i].end(), products.begin() + left, products.begin() + right);
                    break;
                }
            }

            if (!results[i].size())
            {
                break;
            }
        }

        return results;
    }
};

void SearchSUggestionSystemCommon(std::vector<std::string> products, std::string searchWord)
{
    Solution solution;
    solution.suggestedProducts(products, searchWord);
}

TEST(SearchSUggestionSystem, Case1)
{
    SearchSUggestionSystemCommon({"anaconda", "mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse");
}