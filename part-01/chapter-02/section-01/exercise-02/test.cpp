#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(empty_sequence)
{
    std::vector<int> actual1;
    std::vector<int> actual2;
    std::vector<int> expected;

    clrs::reverse_insertion_sort1(actual1.begin(), actual1.end());
    clrs::reverse_insertion_sort2(actual2.begin(), actual2.end());

    ASSERT_EQUAL(actual1, expected);
    ASSERT_EQUAL(actual2, expected);
}

TEST(single_element_sequence)
{
    std::vector<int> actual1  {5};
    std::vector<int> actual2  {5};
    std::vector<int> expected {5};

    clrs::reverse_insertion_sort1(actual1.begin(), actual1.end());
    clrs::reverse_insertion_sort2(actual2.begin(), actual2.end());

    ASSERT_EQUAL(actual1, expected);
    ASSERT_EQUAL(actual2, expected);
}

TEST(nondecreasingly_sorted)
{
    std::vector<int> actual1  {1, 2, 3, 5, 7, 9};
    std::vector<int> actual2  {1, 2, 3, 5, 7, 9};
    std::vector<int> expected {9, 7, 5, 3, 2, 1};

    clrs::reverse_insertion_sort1(actual1.begin(), actual1.end());
    clrs::reverse_insertion_sort2(actual2.begin(), actual2.end());

    ASSERT_EQUAL(actual1, expected);
    ASSERT_EQUAL(actual2, expected);
}

TEST(nonincreasingly_sorted)
{
    std::vector<int> actual1  {101, 41, 16, 10, 5, 2, 1};
    std::vector<int> actual2  {101, 41, 16, 10, 5, 2, 1};
    std::vector<int> expected {101, 41, 16, 10, 5, 2, 1};

    clrs::reverse_insertion_sort1(actual1.begin(), actual1.end());
    clrs::reverse_insertion_sort2(actual2.begin(), actual2.end());

    ASSERT_EQUAL(actual1, expected);
    ASSERT_EQUAL(actual2, expected);
}

TEST(figure_2_2_example)
{
    std::vector<int> actual1  {5, 2, 4, 6, 1, 3};
    std::vector<int> actual2  {5, 2, 4, 6, 1, 3};
    std::vector<int> expected {6, 5, 4, 3, 2, 1};

    clrs::reverse_insertion_sort1(actual1.begin(), actual1.end());
    clrs::reverse_insertion_sort2(actual2.begin(), actual2.end());

    ASSERT_EQUAL(actual1, expected);
    ASSERT_EQUAL(actual2, expected);
}

TEST(exercise_2_1_1_example)
{
    std::vector<int> actual1  {31, 41, 59, 26, 41, 58};
    std::vector<int> actual2  {31, 41, 59, 26, 41, 58};
    std::vector<int> expected {59, 58, 41, 41, 31, 26};

    clrs::reverse_insertion_sort1(actual1.begin(), actual1.end());
    clrs::reverse_insertion_sort2(actual2.begin(), actual2.end());

    ASSERT_EQUAL(actual1, expected);
    ASSERT_EQUAL(actual2, expected);
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
