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
    ListNode *reverseList(ListNode *head)
    {
        if (not head or not head->next)
        {
            return head;
        }

        auto previous = head;
        auto current = head->next;
        previous->next = nullptr;
        while (current)
        {
            auto next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }
};