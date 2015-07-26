#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

using namespace std;

TEST(empty_summands)
{
    vector<bool> actual   {add_binary({}, {})};
    vector<bool> expected {0};

    ASSERT_EQUAL(actual, expected);
}

TEST(one_digit_summands)
{
    vector<bool> actual   {add_binary({1}, {0})};
    vector<bool> expected {0, 1};

    ASSERT_EQUAL(actual, expected);
}

TEST(adding_ones)
{
    vector<bool> actual   {add_binary({1}, {1})};
    vector<bool> expected {1, 0};

    ASSERT_EQUAL(actual, expected);
}

TEST(leading_zeroes)
{
    vector<bool> actual   {add_binary({0, 1}, {0, 0})};
    vector<bool> expected {0, 0, 1};

    ASSERT_EQUAL(actual, expected);
}

TEST(with_carry)
{
    vector<bool> actual   {add_binary({1, 0}, {1, 1})};
    vector<bool> expected {1, 0, 1};

    ASSERT_EQUAL(actual, expected);
}

TEST(most_significant_bit_carry)
{
    vector<bool> actual   {add_binary({1, 1, 1}, {0, 1, 1})};
    vector<bool> expected {1, 0, 1, 0};

    ASSERT_EQUAL(actual, expected);
}

int main()
{
    BEGIN();

    RUN_TEST(empty_summands);
    RUN_TEST(one_digit_summands);
    RUN_TEST(adding_ones);
    RUN_TEST(leading_zeroes);
    RUN_TEST(with_carry);
    RUN_TEST(most_significant_bit_carry);

    END();
}
