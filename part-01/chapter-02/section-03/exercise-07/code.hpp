#include <algorithm>
#include <vector>

#include "../exercise-05/code.hpp"

namespace clrs
{
    template <typename InputIterator, typename T>
    bool two_sum1(InputIterator first, InputIterator last, const T& value)
    {
        std::vector<T> sorted(first, last);
        std::sort(sorted.begin(), sorted.end());

        for (auto i = sorted.cbegin(); i != sorted.cend(); ++i)
        {
            auto j = clrs::binary_search(sorted.cbegin(),
                                         sorted.cend(),
                                         value - *i);

            if (j != sorted.cend() && j != i)
            {
                return true;
            }
        }

        return false;
    }

    /*
     * Another algorithm that does not make use of binary search but has an
     * ugly edge case because of the use of iterators.
     */

    template <typename InputIterator, typename T>
    bool two_sum2(InputIterator first, InputIterator last, const T& value)
    {
        if (first == last)
        {
            return false;
        }

        std::vector<T> sorted(first, last);
        std::sort(sorted.begin(), sorted.end());

        for (auto i = sorted.cbegin(), j = sorted.cend() - 1; i < j; )
        {
            if (*i + *j < value)
            {
                ++i;
            }
            else if (*i + *j > value)
            {
                --j;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
}
