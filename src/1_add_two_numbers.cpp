#include <gtest/gtest.h>

class Solution
{
public:
    //   Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return makeList(makeNumber(l1) + makeNumber(l2));
    }

    int makeNumber(ListNode *l)
    {
        int sum = 0;
        int base = 1;
        while (l)
        {
            sum += l->val * base;
            base *= 10;

            l = l->next;
        }

        return sum;
    }

    // 12345344634
    ListNode *makeList(int number)
    {
        int base = 10;
        ListNode *prev = nullptr;
        ListNode *first = new ListNode(0);
        ;

        while (number > 0)
        {
            int temp = number % base;
            number -= temp;
            temp /= (base / 10);
            base *= 10;
            if (!prev)
            {
                first->val = temp;
                prev = first;
            }
            else
            {
                auto next = new ListNode(temp);
                prev->next = next;
                prev = next;
            }
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

void AddTwoNumbersCommon(int val1, int val2)
{
    Solution solution;
    auto l1 = solution.makeList(val1);
    auto l2 = solution.makeList(val2);
    auto result = solution.addTwoNumbers(l1, l2);

    EXPECT_EQ(solution.makeNumber(result), val1 + val2);

    solution.deleteList(l1);
    solution.deleteList(l2);
    solution.deleteList(result);
}

TEST(AddTwoNumbers, Case1)
{
    AddTwoNumbersCommon(342, 456);
}

TEST(AddTwoNumbers, Case2)
{
    AddTwoNumbersCommon(0, 0);
}

TEST(AddTwoNumbers, Case3)
{
    AddTwoNumbersCommon(9999999, 9999);
}