#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(empty_sequence)
{
    std::vector<int> actual;
    std::vector<int> expected;

    clrs::selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(single_element_sequence)
{
    std::vector<int> actual   {5};
    std::vector<int> expected {5};

    clrs::selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(nondecreasingly_sorted)
{
    std::vector<int> actual   {1, 2, 3, 5, 7, 9};
    std::vector<int> expected {1, 2, 3, 5, 7, 9};

    clrs::selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(nonincreasingly_sorted)
{
    std::vector<int> actual   {101, 41, 16, 10, 5, 2, 1};
    std::vector<int> expected {1, 2, 5, 10, 16, 41, 101};

    clrs::selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(figure_2_2_example)
{
    std::vector<int> actual   {5, 2, 4, 6, 1, 3};
    std::vector<int> expected {1, 2, 3, 4, 5, 6};

    clrs::selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(exercise_2_1_1_example)
{
    std::vector<int> actual   {31, 41, 59, 26, 41, 58};
    std::vector<int> expected {26, 31, 41, 41, 58, 59};

    clrs::selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

int main()
{
    BEGIN();

    RUN_TEST(empty_sequence);
    RUN_TEST(single_element_sequence);
    RUN_TEST(nondecreasingly_sorted);
    RUN_TEST(nonincreasingly_sorted);
    RUN_TEST(figure_2_2_example);
    RUN_TEST(exercise_2_1_1_example);

    END();
}
