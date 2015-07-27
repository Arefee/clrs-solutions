#include <vector>

namespace clrs
{
    std::vector<bool> add_binary(const std::vector<bool>& left,
                                 const std::vector<bool>& right)
    {
        unsigned int carry {0};
        std::vector<bool> sum(left.size() + 1);

        for (auto i = sum.size() - 1; i >= 1; --i)
        {
            sum[i] = (left[i - 1] + right[i - 1] + carry) % 2;
            carry  = (left[i - 1] + right[i - 1] + carry) / 2;
        }

        sum.front() = carry;

        return sum;
    }
}
