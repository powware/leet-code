#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        auto greater = [](auto &lhs, auto &rhs)
        { return lhs->val > rhs->val; };

        std::vector<ListNode *> sorted;
        for (auto list : lists)
        {
            auto next = list;
            while (next)
            {
                sorted.push_back(next);
                std::push_heap(sorted.begin(), sorted.end(), greater);
                next = next->next;
            }
        }
        std::sort_heap(sorted.begin(), sorted.end(), greater);

        ListNode *prev;
        for (auto node : sorted)
        {
            if (prev)
            {
                prev->next = node;
            }
            prev = node;
        }

        return prev;
    }
};