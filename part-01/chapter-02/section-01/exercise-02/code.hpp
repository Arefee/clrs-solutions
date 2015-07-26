#include <utility>

template <typename RandomAccessIterator>
void reverse_insertion_sort(RandomAccessIterator first,
                            RandomAccessIterator last)
{
    for (auto i = first; i != last; ++i)
    {
        auto key = *i;
        auto j   = i - 1;

        for (; j >= first && *j < key; --j)
        {
            *(j + 1) = *j;
        }

        *(j + 1) = key;
    }
}

/*
 * More compact but potentially slower because of the more iterator
 * dereferences and the use of swaps instead of assignments.
 */

// template <typename RandomAccessIterator>
// void reverse_insertion_sort(RandomAccessIterator first,
//                             RandomAccessIterator last)
// {
//     for (auto i = first; i != last; ++i)
//     {
//         for (auto j = i; j >= first && *j > *(j - 1); --j)
//         {
//             std::swap(*j, *(j - 1));
//         }
//     }
// }
