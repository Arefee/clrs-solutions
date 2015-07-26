#include <utility>

using namespace std;

template <typename InputIterator>
void selection_sort(InputIterator first, InputIterator last)
{
    for (auto i = first; i + 1 < last; ++i)
    {
        auto min = i;

        for (auto j = i + 1; j < last; ++j)
        {
            if (*j < *min)
            {
                min = j;
            }
        }

        swap(*i, *min);
    }
}
