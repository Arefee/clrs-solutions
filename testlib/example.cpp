#include <map>
#include <string>
#include <vector>

#include "testlib.hpp"

TEST(one_plus_one_is_two)
{
    ASSERT_EQUAL(1 + 1, 2);
}

TEST(almost_equal)
{
    ASSERT_ALMOST_EQUAL(1.001, 1.000, 2);
}

TEST(three_is_not_even)
{
    ASSERT_FALSE(3 % 2 == 0);
}

TEST(five_is_odd)
{
    ASSERT_TRUE(5 % 2 != 0);
}

TEST(different_strings)
{
    string a = "c";
    string b = "c++";

    ASSERT_EQUAL(a, b);
}

TEST(different_vectors)
{
    vector<int> left  {5, 7, 9};
    vector<int> right {1, 4, 8};

    ASSERT_EQUAL(left, right);
}

TEST(different_maps)
{
    map<string, string> left  {{"bulgaria", "sofia"}, {"canada", "ottawa"}};
    map<string, string> right {{"ala", "bala"},       {"porto", "kala"}};

    ASSERT_EQUAL(left, right);
}

int main(void)
{
    BEGIN();

    RUN_TEST(one_plus_one_is_two);
    RUN_TEST(almost_equal);
    RUN_TEST(three_is_not_even);
    RUN_TEST(five_is_odd);
    RUN_TEST(different_strings);
    RUN_TEST(different_vectors);
    RUN_TEST(different_maps);

    END();
}
