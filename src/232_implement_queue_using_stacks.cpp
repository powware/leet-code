#include <stack>

#include <gtest/gtest.h>

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        enqueue.push(x);
    }

    int pop()
    {
        if (dequeue.empty())
        {
            EnqueueToDequeue();
        }

        int temp = dequeue.top();

        dequeue.pop();

        return temp;
    }

    int peek()
    {
        if (dequeue.empty())
        {
            EnqueueToDequeue();
        }

        return dequeue.top();
    }

    bool empty()
    {
        return enqueue.empty() && dequeue.empty();
    }

private:
    std::stack<int> enqueue;
    std::stack<int> dequeue;

    void EnqueueToDequeue()
    {
        while (!enqueue.empty())
        {
            dequeue.push(enqueue.top());
            enqueue.pop();
        }
    }
};

TEST(ImplementQueueUsingStacks, Case1)
{
    MyQueue obj;
    obj.push(1);
    int param_2 = obj.pop();
    int param_3 = obj.peek();
    bool param_4 = obj.empty();
}