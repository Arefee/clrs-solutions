#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(empty_sequence)
{
    std::vector<int> sequence;

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 1) ==
                sequence.cend());
}

TEST(single_element_sequence)
{
    std::vector<int> sequence {42};

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 42) ==
                sequence.cbegin());

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 10) ==
                sequence.cend());
}

TEST(find_first_element)
{
    std::vector<int> sequence {9, 23, 34, 345};

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 9) ==
                sequence.cbegin());
}

TEST(find_last_element)
{
    std::vector<int> sequence {9, 23, 34, 345};

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 345) ==
                sequence.cbegin() + 3);
}

TEST(find_inner_element)
{
    std::vector<int> sequence {8, 78, 203, 238, 300, 667, 1023};

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 238) ==
                sequence.cbegin() + 3);

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 667) ==
                sequence.cbegin() + 5);
}

TEST(missing_element)
{
    std::vector<int> sequence {1, 5, 7, 9, 42, 101};

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 0) ==
                sequence.cend());

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 6) ==
                sequence.cend());

    ASSERT_TRUE(clrs::binary_search(sequence.cbegin(), sequence.cend(), 111) ==
                sequence.cend());
}

int main()
{
    BEGIN();

    RUN_TEST(empty_sequence);
    RUN_TEST(single_element_sequence);
    RUN_TEST(find_first_element);
    RUN_TEST(find_last_element);
    RUN_TEST(find_inner_element);
    RUN_TEST(missing_element);

    END();
}
