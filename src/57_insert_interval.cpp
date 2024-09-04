#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {

        bool first_inside = false;
        bool second_inside = false;
        std::size_t first = 0;
        std::size_t second = 0;
        for (first = 0; first < intervals.size(); ++first)
        {
            if (newInterval[0] >= intervals[first][0] && newInterval[0] <= intervals[first][1])
            {
                first_inside = true;
                break;
            }
            else if (newInterval[0] < intervals[first][0])
            {
                break;
            }
        }

        for (second = first; second < intervals.size(); ++second)
        {
            if (newInterval[1] >= intervals[second][0] && newInterval[1] <= intervals[second][1])
            {
                second_inside = true;
                break;
            }
            else if (newInterval[1] < intervals[second][0])
            {
                break;
            }
        }

        if (!first_inside && !second_inside)
        {
            intervals.insert(intervals.begin() + first++, newInterval);
            second++;
        }
        else if (first_inside && second_inside)
        {
            intervals[first++][1] = intervals[second++][1];
        }
        else if (first_inside && !second_inside)
        {
            intervals[first++][1] = newInterval[1];
        }
        else if (!first_inside && second_inside)
        {
            intervals[second][0] = newInterval[0];
        }

        intervals.erase(intervals.begin() + first, intervals.begin() + first + (second - first));

        return intervals;
    }
};

void InsertIntervalCommon(std::vector<std::vector<int>> intervals, std::vector<int> newInterval)
{
    Solution solution;

    solution.insert(intervals, newInterval);
}

// TEST(InsertInterval, Case1)
// {
//     InsertIntervalCommon({{1, 3}, {6, 9}}, {2, 5});
// }

TEST(InsertInterval, Case1)
{
    InsertIntervalCommon({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8});
}

// TEST(InsertInterval, Case1)
// {
//     InsertIntervalCommon({{1, 5}}, {0, 6});
// }
