#include <vector>

#include "code.hpp"
#include "../../../../testlib/testlib.hpp"

TEST(empty_set)
{
    std::vector<int> set;

    ASSERT_FALSE(clrs::two_sum1(set.cbegin(), set.cend(), 0));
    ASSERT_FALSE(clrs::two_sum1(set.cbegin(), set.cend(), 5));

    ASSERT_FALSE(clrs::two_sum2(set.cbegin(), set.cend(), 0));
    ASSERT_FALSE(clrs::two_sum2(set.cbegin(), set.cend(), 5));
}

TEST(single_element_set)
{
    std::vector<int> set {1};

    ASSERT_FALSE(clrs::two_sum1(set.cbegin(), set.cend(), 1));
    ASSERT_FALSE(clrs::two_sum1(set.cbegin(), set.cend(), 2));

    ASSERT_FALSE(clrs::two_sum2(set.cbegin(), set.cend(), 1));
    ASSERT_FALSE(clrs::two_sum2(set.cbegin(), set.cend(), 2));
}

TEST(possible_two_sum)
{
    std::vector<int> set {8, 983, 62, 3, 1, 6};

    ASSERT_TRUE(clrs::two_sum1(set.cbegin(), set.cend(), 7));

    ASSERT_TRUE(clrs::two_sum2(set.cbegin(), set.cend(), 7));
}

TEST(impossible_two_sum)
{
    std::vector<int> set {8, 65, 3, 43, 8787, 23, 425};

    ASSERT_FALSE(clrs::two_sum1(set.cbegin(), set.cend(), 1));

    ASSERT_FALSE(clrs::two_sum2(set.cbegin(), set.cend(), 1));
}

TEST(multiset)
{
    std::vector<int> multiset {5, 1, 0, 1};

    ASSERT_TRUE(clrs::two_sum1(multiset.cbegin(), multiset.cend(), 2));

    ASSERT_TRUE(clrs::two_sum2(multiset.cbegin(), multiset.cend(), 2));
}

int main()
{
    BEGIN();

    RUN_TEST(empty_set);
    RUN_TEST(single_element_set);
    RUN_TEST(possible_two_sum);
    RUN_TEST(impossible_two_sum);
    RUN_TEST(multiset);

    END();
}
