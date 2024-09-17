#include <vector>
#include <unordered_set>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<int> quick(n);
        std::vector<std::vector<std::string>> result;
        Queen(result, quick, 0, n);
        return result;
    }

private:
    void Queen(std::vector<std::vector<std::string>> &result, std::vector<int> &quick, int row, int n)
    {
        if (row == n)
        {
            std::vector<std::string> subresult;
            subresult.reserve(n);
            std::string row(n, '.');
            for (int i = 0; i < n; ++i)
            {
                auto copy = row;
                copy[quick[i]] = 'Q';
                subresult.push_back(std::move(copy));
            }

            result.push_back(std::move(subresult));

            return;
        }

        for (int i = 0; i < n; ++i)
        {
            bool col = false;
            bool diag = false;
            for (int j = 0; j < row; ++j)
            {
                if (i == quick[j])
                {
                    col = true;
                    break;
                }
                if (std::abs(i - quick[j]) == std::abs(row - j))
                {
                    diag = true;
                    break;
                }
            }

            if (col or diag)
            {
                continue;
            }

            quick[row] = i;
            Queen(result, quick, row + 1, n);
        }
    }
};

void NQueensCommon(int n)
{
    Solution solution;

    solution.solveNQueens(n);
}

TEST(NQueens, Case0)
{
    NQueensCommon(5);
}
