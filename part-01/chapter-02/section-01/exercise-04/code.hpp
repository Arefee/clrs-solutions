#include <vector>

using namespace std;

vector<bool> add_binary(const vector<bool>& left, const vector<bool>& right)
{
    unsigned int carry {0};
    vector<bool> sum(left.size() + 1);

    for (auto i = sum.size() - 1; i >= 1; --i)
    {
        sum[i] = (left[i - 1] + right[i - 1] + carry) % 2;
        carry  = (left[i - 1] + right[i - 1] + carry) / 2;
    }

    sum.front() = carry;

    return sum;
}
