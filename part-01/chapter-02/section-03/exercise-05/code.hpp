#include <iterator>

namespace clrs
{
    template <typename ForwardIterator, typename T>
    ForwardIterator binary_search(ForwardIterator first,
                                  ForwardIterator last,
                                  const T& value)
    {
        auto length = std::distance(first, last);

        while (length > 0)
        {
            auto middle = first;
            auto step   = length / 2;

            std::advance(middle, step);

            if (*middle < value)
            {
                first   = ++middle;
                length -= step + 1;
            }
            else if (*middle > value)
            {
                length = step;
            }
            else
            {
                return middle;
            }
        }

        return last;
    }
}
