#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(two_empty_sequences)
{
    std::vector<int> actual;
    std::vector<int> expected;

    std::vector<int> left;
    std::vector<int> right;

    ASSERT_TRUE(clrs::merge(left.cbegin(),  left.cend(),
                            right.cbegin(), right.cend(),
                            actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(one_empty_sequence)
{
    std::vector<int> actual(3);
    std::vector<int> expected {1, 2, 3};

    std::vector<int> left;
    std::vector<int> right {1, 2, 3};

    ASSERT_TRUE(clrs::merge(left.cbegin(),  left.cend(),
                            right.cbegin(), right.cend(),
                            actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(two_single_element_sequences)
{
    std::vector<int> actual(2);
    std::vector<int> expected {5, 7};

    std::vector<int> left  {7};
    std::vector<int> right {5};

    ASSERT_TRUE(clrs::merge(left.cbegin(),  left.cend(),
                            right.cbegin(), right.cend(),
                            actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(noninterleaving_sequences)
{
    std::vector<int> actual(6);
    std::vector<int> expected {9, 10, 13, 87, 100, 101};

    std::vector<int> left  {9, 10};
    std::vector<int> right {13, 87, 100, 101};

    ASSERT_TRUE(clrs::merge(left.cbegin(),  left.cend(),
                            right.cbegin(), right.cend(),
                            actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(interleaving_sequences)
{
    std::vector<int> actual(6);
    std::vector<int> expected {2, 89, 822, 7430, 87301, 923812};

    std::vector<int> left  {89, 822, 923812};
    std::vector<int> right {2, 7430, 87301};

    ASSERT_TRUE(clrs::merge(left.cbegin(),  left.cend(),
                            right.cbegin(), right.cend(),
                            actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(return_iterator_with_larger_output_container)
{
    std::vector<int> actual(4);

    std::vector<int> left  {1};
    std::vector<int> right {2, 3};

    ASSERT_TRUE(clrs::merge(left.cbegin(),  left.cend(),
                            right.cbegin(), right.cend(),
                            actual.begin()) ==
                actual.end() - 1);
}

int main()
{
    BEGIN();

    RUN_TEST(two_empty_sequences);
    RUN_TEST(one_empty_sequence);
    RUN_TEST(two_single_element_sequences);
    RUN_TEST(noninterleaving_sequences);
    RUN_TEST(interleaving_sequences);
    RUN_TEST(return_iterator_with_larger_output_container);

    END();
}
