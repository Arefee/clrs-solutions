#include <algorithm>

namespace clrs
{
    template <typename LeftInputIterator,
              typename RightInputIterator,
              typename OutputIterator>
    OutputIterator merge(LeftInputIterator  left_first,
                         LeftInputIterator  left_last,
                         RightInputIterator right_first,
                         RightInputIterator right_last,
                         OutputIterator     result)
    {
        while (left_first != left_last && right_first != right_last)
        {
            if (*left_first < *right_first)
            {
                *result = *left_first;
                ++left_first;
            }
            else
            {
                *result = *right_first;
                ++right_first;
            }

            ++result;
        }

        result = copy(left_first,  left_last, result);
        result = copy(right_first, right_last, result);

        return result;
    }
}
