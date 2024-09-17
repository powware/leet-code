#include <vector>
#include <unordered_map>
#include <queue>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::queue<int> to_resolve;
        std::vector<int> result;
        result.reserve(numCourses);
        std::unordered_map<int, std::unordered_map<int, bool>> dependencies;
        std::unordered_map<int, std::vector<int>> resolutions;

        for (auto prerequisite : prerequisites)
        {
            dependencies[prerequisite[0]][prerequisite[1]] = true;
            resolutions[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (auto it = dependencies.find(i); it == dependencies.end())
            {
                to_resolve.push(i);
            }
        }

        while (not to_resolve.empty())
        {
            auto course = to_resolve.front();
            to_resolve.pop();
            result.push_back(course);
            if (auto resolution = resolutions.find(course); resolution != resolutions.end())
            {
                for (auto resolved_course : resolution->second)
                {
                    auto resolved_course_dependencies = dependencies.find(resolved_course);
                    resolved_course_dependencies->second.erase(course);
                    if (resolved_course_dependencies->second.empty())
                    {
                        to_resolve.push(resolved_course);
                    }
                }
            }
        }

        return result.size() == std::size_t(numCourses) ? result : std::vector<int>();
    }
};

void CourseSchedule2Common(int numCourses, std::vector<std::vector<int>> prerequisites, std::vector<int> expected)
{
    Solution solution;
    auto result = solution.findOrder(numCourses, prerequisites);
    ASSERT_EQ(result.size(), expected.size());
    for (std::size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(CourseSchedule2, Case1)
{
    CourseSchedule2Common(3, {{1, 0}, {1, 2}, {0, 1}}, {});
}

TEST(CourseSchedule2, Case2)
{
    CourseSchedule2Common(2, {}, {0, 1});
}

TEST(CourseSchedule2, Case3)
{
    CourseSchedule2Common(2, {{1, 0}}, {0, 1});
}

TEST(CourseSchedule2, Case4)
{
    CourseSchedule2Common(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3});
}
