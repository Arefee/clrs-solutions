#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

using namespace std;

TEST(two_empty_sequences)
{
    vector<int> actual;
    vector<int> expected;

    vector<int> left;
    vector<int> right;

    ASSERT_TRUE(mmerge(left.cbegin(),  left.cend(),
                       right.cbegin(), right.cend(),
                       actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(one_empty_sequence)
{
    vector<int> actual(3);
    vector<int> expected {1, 2, 3};

    vector<int> left;
    vector<int> right {1, 2, 3};

    ASSERT_TRUE(mmerge(left.cbegin(),  left.cend(),
                       right.cbegin(), right.cend(),
                       actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(two_single_element_sequences)
{
    vector<int> actual(2);
    vector<int> expected {5, 7};

    vector<int> left  {7};
    vector<int> right {5};

    ASSERT_TRUE(mmerge(left.cbegin(),  left.cend(),
                       right.cbegin(), right.cend(),
                       actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(noninterleaving_sequences)
{
    vector<int> actual(6);
    vector<int> expected {9, 10, 13, 87, 100, 101};

    vector<int> left  {9, 10};
    vector<int> right {13, 87, 100, 101};

    ASSERT_TRUE(mmerge(left.cbegin(),  left.cend(),
                       right.cbegin(), right.cend(),
                       actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(interleaving_sequences)
{
    vector<int> actual(6);
    vector<int> expected {2, 89, 822, 7430, 87301, 923812};

    vector<int> left  {89, 822, 923812};
    vector<int> right {2, 7430, 87301};

    ASSERT_TRUE(mmerge(left.cbegin(),  left.cend(),
                       right.cbegin(), right.cend(),
                       actual.begin()) ==
                actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(return_iterator_with_larger_output_container)
{
    vector<int> actual(4);

    vector<int> left  {1};
    vector<int> right {2, 3};

    ASSERT_TRUE(mmerge(left.cbegin(),  left.cend(),
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
