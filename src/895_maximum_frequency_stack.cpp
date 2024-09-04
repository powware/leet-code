#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

#include <gtest/gtest.h>

class FreqStack
{
public:
    FreqStack()
    {
    }

    void push(int val)
    {
        if (frequencies_[val])
        {
            ++frequencies_[val]->frequency;
            frequencies_[val]->pushed_.push(size_);
            std::make_heap(max_frequencies_.begin(), max_frequencies_.end(), Frequency::less);
        }
        else
        {
            auto frequency = std::make_unique<Frequency>(val);
            frequency->pushed_.push(size_);
            max_frequencies_.push_back(frequency.get());
            frequencies_[val] = std::move(frequency);
            std::push_heap(max_frequencies_.begin(), max_frequencies_.end(), Frequency::less);
        }
        ++size_;
    }

    int pop()
    {
        std::pop_heap(max_frequencies_.begin(), max_frequencies_.end(), Frequency::less);
        auto max = max_frequencies_.back();
        max->pushed_.pop();
        int value = max->value;
        if (--max->frequency <= 0)
        {
            max_frequencies_.pop_back();
            frequencies_[value] = nullptr;
        }
        else
        {
            std::push_heap(max_frequencies_.begin(), max_frequencies_.end(), Frequency::less);
        }

        return value;
    }

private:
    struct Frequency
    {
        int value;
        int frequency = 1;
        std::stack<int> pushed_;

        Frequency(int value) : value(value) {};

        static bool less(Frequency *lhs, Frequency *rhs)
        {
            if (lhs->frequency == rhs->frequency)
            {
                return lhs->pushed_.top() < rhs->pushed_.top();
            }
            return lhs->frequency < rhs->frequency;
        }
    };

    int size_ = 0;
    std::vector<Frequency *> max_frequencies_;
    std::unordered_map<int, std::unique_ptr<Frequency>> frequencies_;
};

// void PeakIndexInMountainArrayCommon(std::vector<int> nums)
// {
//     Solution solution;
//     auto result = solution.peakIndexInMountainArray(nums);
// }

// TEST(PeakIndexInMountainArray, Case1)
// {
//     PeakIndexInMountainArrayCommon({0, 9, 10, 7, 6, 5, 4, 3, 2, 1});
// }
