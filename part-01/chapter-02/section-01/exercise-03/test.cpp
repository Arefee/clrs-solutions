#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(empty_sequence)
{
    std::vector<int> sequence;

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 1) ==
                sequence.cend());
}

TEST(single_element_sequence)
{
    std::vector<int> sequence {42};

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 42) ==
                sequence.cbegin());

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 10) ==
                sequence.cend());
}

TEST(find_first_element)
{
    std::vector<int> sequence {34, 23, 9, 345};

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 34) ==
                sequence.cbegin());
}

TEST(find_last_element)
{
    std::vector<int> sequence {34, 23, 9, 345};

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 345) ==
                sequence.cbegin() + 3);
}

TEST(find_inner_element)
{
    std::vector<int> sequence {78, 667, 203, 8, 1023, 238, 300};

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 8) ==
                sequence.cbegin() + 3);

    ASSERT_TRUE(clrs::linear_search(sequence.cbegin(), sequence.cend(), 238) ==
                sequence.cbegin() + 5);
}

int main()
{
    BEGIN();

    RUN_TEST(empty_sequence);
    RUN_TEST(single_element_sequence);
    RUN_TEST(find_first_element);
    RUN_TEST(find_last_element);
    RUN_TEST(find_inner_element);

    END();
}
