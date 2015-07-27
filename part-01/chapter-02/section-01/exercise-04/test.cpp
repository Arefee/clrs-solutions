#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(empty_summands)
{
    std::vector<bool> actual   {clrs::add_binary({}, {})};
    std::vector<bool> expected {0};

    ASSERT_EQUAL(actual, expected);
}

TEST(one_digit_summands)
{
    std::vector<bool> actual   {clrs::add_binary({1}, {0})};
    std::vector<bool> expected {0, 1};

    ASSERT_EQUAL(actual, expected);
}

TEST(adding_ones)
{
    std::vector<bool> actual   {clrs::add_binary({1}, {1})};
    std::vector<bool> expected {1, 0};

    ASSERT_EQUAL(actual, expected);
}

TEST(leading_zeroes)
{
    std::vector<bool> actual   {clrs::add_binary({0, 1}, {0, 0})};
    std::vector<bool> expected {0, 0, 1};

    ASSERT_EQUAL(actual, expected);
}

TEST(with_carry)
{
    std::vector<bool> actual   {clrs::add_binary({1, 0}, {1, 1})};
    std::vector<bool> expected {1, 0, 1};

    ASSERT_EQUAL(actual, expected);
}

TEST(most_significant_bit_carry)
{
    std::vector<bool> actual   {clrs::add_binary({1, 1, 1}, {0, 1, 1})};
    std::vector<bool> expected {1, 0, 1, 0};

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
