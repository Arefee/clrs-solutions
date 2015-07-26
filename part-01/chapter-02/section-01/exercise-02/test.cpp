#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

using namespace std;

TEST(empty_sequence)
{
    vector<int> actual;
    vector<int> expected;

    reverse_insertion_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(single_element_sequence)
{
    vector<int> actual   {5};
    vector<int> expected {5};

    reverse_insertion_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(nondecreasingly_sorted)
{
    vector<int> actual   {1, 2, 3, 5, 7, 9};
    vector<int> expected {9, 7, 5, 3, 2, 1};

    reverse_insertion_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(nonicreasingly_sorted)
{
    vector<int> actual   {101, 41, 16, 10, 5, 2, 1};
    vector<int> expected {101, 41, 16, 10, 5, 2, 1};

    reverse_insertion_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(figure_2_2_example)
{
    vector<int> actual   {5, 2, 4, 6, 1, 3};
    vector<int> expected {6, 5, 4, 3, 2, 1};

    reverse_insertion_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(exercise_2_1_1_example)
{
    vector<int> actual   {31, 41, 59, 26, 41, 58};
    vector<int> expected {59, 58, 41, 41, 31, 26};

    reverse_insertion_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

int main()
{
    BEGIN();

    RUN_TEST(empty_sequence);
    RUN_TEST(single_element_sequence);
    RUN_TEST(nondecreasingly_sorted);
    RUN_TEST(nonicreasingly_sorted);
    RUN_TEST(figure_2_2_example);
    RUN_TEST(exercise_2_1_1_example);

    END();
}
