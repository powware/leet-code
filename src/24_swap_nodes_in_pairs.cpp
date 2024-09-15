#include <vector>
#include <array>

#include <gtest/gtest.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (not head or not head->next)
        {
            return head;
        }

        ListNode *pprevious = nullptr;
        auto previous = head;
        auto current = head->next;
        previous->next = nullptr;
        head = current;
        while (current)
        {
            auto next = current->next;
            current->next = previous;
            previous->next = next;
            if (pprevious)
            {
                pprevious->next = current;
            }
            pprevious = previous;
            current = next;

            if (not current)
            {
                break;
            }
            previous = current;
            current = current->next;
        }

        return head;
    }
};

static ListNode *MakeList(int n)
{
    ListNode *first = nullptr;
    ListNode **next = &first;
    for (int i = 0; i < n; ++i)
    {
        *next = new ListNode(i + 1);
        next = &((*next)->next);
    }

    return first;
}

void SwapNodesInPairsCommon(int n)
{
    Solution solution;
    auto list = MakeList(n);
    solution.swapPairs(list);
}

TEST(SwapNodesInPairs, Case1)
{
    SwapNodesInPairsCommon(5);
}