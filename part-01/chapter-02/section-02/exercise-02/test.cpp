#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

using namespace std;

TEST(empty_sequence)
{
    vector<int> actual;
    vector<int> expected;

    selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(single_element_sequence)
{
    vector<int> actual   {5};
    vector<int> expected {5};

    selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(nondecreasingly_sorted)
{
    vector<int> actual   {1, 2, 3, 5, 7, 9};
    vector<int> expected {1, 2, 3, 5, 7, 9};

    selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(nonincreasingly_sorted)
{
    vector<int> actual   {101, 41, 16, 10, 5, 2, 1};
    vector<int> expected {1, 2, 5, 10, 16, 41, 101};

    selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(figure_2_2_example)
{
    vector<int> actual   {5, 2, 4, 6, 1, 3};
    vector<int> expected {1, 2, 3, 4, 5, 6};

    selection_sort(actual.begin(), actual.end());

    ASSERT_EQUAL(actual, expected);
}

TEST(exercise_2_1_1_example)
{
    vector<int> actual   {31, 41, 59, 26, 41, 58};
    vector<int> expected {26, 31, 41, 41, 58, 59};

    selection_sort(actual.begin(), actual.end());

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
