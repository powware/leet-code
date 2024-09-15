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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (not head or not head->next or left == right)
        {
            return head;
        }

        int pos = 1;
        ListNode *previous = head;
        ListNode *current = head->next;
        ListNode *before = nullptr;
        ListNode *first = nullptr;

        while (current and pos < right)
        {
            if (pos < left)
            {
                before = previous;
            }

            auto next = current->next;
            if (pos >= left)
            {
                if (pos == left)
                {
                    first = previous;
                }

                current->next = previous;
            }
            previous = current;
            current = next;
            ++pos;
        }

        if (before)
        {
            before->next = previous;
        }

        first->next = current;

        return before ? head : previous;
    }
};

ListNode *MakeList(int n)
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

void ReverseLinkedList2Common(int n, int left, int right)
{
    Solution solution;
    auto list = MakeList(n);
    // ASSERT_EQ(, expected);
    solution.reverseBetween(list, left, right);
}

TEST(ReverseLinkedList2, Case1)
{
    ReverseLinkedList2Common(5, 2, 4);
}