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
        {
            return lhs->val > rhs->val;
        };

        std::erase_if(lists, [](auto node)
                      { return node == nullptr; });

        if (!lists.size())
        {
            return nullptr;
        }

        ListNode *first = nullptr;
        ListNode **next = &first;
        std::make_heap(lists.begin(), lists.end(), greater);
        while (lists.size())
        {
            std::pop_heap(lists.begin(), lists.end(), greater);
            *next = lists.back();
            next = &((*next)->next);
            if (*next)
            {
                lists.back() = *next;
                std::push_heap(lists.begin(), lists.end(), greater);
            }
            else
            {
                lists.pop_back();
            }
        }

        return first;
    }

    ListNode *makeList(std::vector<int> &list)
    {
        ListNode *first = nullptr;
        ListNode **next = &first;
        std::sort(list.begin(), list.end(), std::less<>());
        for (auto node : list)
        {
            *next = new ListNode(node);
            next = &((*next)->next);
        }

        return first;
    }

    void deleteList(ListNode *l)
    {
        ListNode *next;
        while (l)
        {
            next = l->next;
            delete l;
            l = next;
        }
    }
};

void MergeKSortedListsCommon(std::vector<std::vector<int>> numss)
{
    Solution solution;
    std::vector<ListNode *> lists;
    for (auto &nums : numss)
    {
        lists.push_back(solution.makeList(nums));
    }
    auto result = solution.mergeKLists(lists);

    if (result)
    {
        solution.deleteList(result);
    }
}

// TEST(MergeKSortedLists, Case1)
// {
//     MergeKSortedListsCommon({{1, 2, 3, 4, 7, 8, 9}, {1, 1, 2, 5, 5, 5, 5}});
// }

TEST(MergeKSortedLists, Case2)
{
    MergeKSortedListsCommon({{}, {}});
}

TEST(MergeKSortedLists, Case3)
{
    MergeKSortedListsCommon({{1, 4, 5}, {1, 3, 4}, {2, 6}});
}