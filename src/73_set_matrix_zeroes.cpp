#include <vector>
#include <optional>
#include <array>

#include <gtest/gtest.h>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        bool zero_first_row = false;
        bool zero_first_column = false;

        const size_t rows = matrix.size();
        const size_t columns = matrix[0].size();

        for (size_t i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
            {
                zero_first_column = true;
            }
        }

        for (size_t i = 0; i < columns; i++)
        {
            if (matrix[0][i] == 0)
            {
                zero_first_row = true;
            }
        }

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (size_t i = 1; i < rows; i++)
        {
            for (size_t j = 1; j < columns; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (zero_first_row)
        {
            for (size_t i = 0; i < columns; i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (zero_first_column)
        {
            for (size_t i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

void SetMatrixZeroesCommon(std::vector<std::vector<int>> matrix)
{
    Solution solution;

    solution.setZeroes(matrix);
}

// TEST(SetMatrixZeroes, Case1)
// {
//     SetMatrixZeroesCommon({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
// }

// TEST(SetMatrixZeroes, Case2)
// {
//     SetMatrixZeroesCommon({{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}});
// }

TEST(SetMatrixZeroes, Case2)
{
    SetMatrixZeroesCommon({{1, 1, 2, 1}, {3, 4, 0, 2}, {1, 3, 1, 5}});
}

// TEST(SetMatrixZeroes, Case3)
// {
//     SetMatrixZeroesCommon(13, 377);
// }