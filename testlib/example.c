#include "test.h"

TEST(one_plus_one)
{
    ASSERT_EQUAL(1 + 1, 2);
}

TEST(almost_equal)
{
    ASSERT_ALMOST_EQUAL(1.12, 1.12, 2);
}

TEST(true_is_false)
{
    ASSERT_FALSE(0);
}

TEST(false_is_true)
{
    ASSERT_TRUE(1 + 1);
}

TEST(strings)
{
    ASSERT_STRING_EQUAL("macros", "macros");
}

int me[]  = {1, 2, 3};
int you[] = {1, 2, 3};

TEST(arrays)
{
    ASSERT_ARRAY_EQUAL(me, you);
}

TEST(wait)
{
    for (int i = 0; i < 2000000000; ++i)
    { }
}

int main(void)
{
    BEGIN();

    RUN_TEST(one_plus_one);
    RUN_TEST(almost_equal);
    RUN_TEST(true_is_false);
    RUN_TEST(false_is_true);
    RUN_TEST(strings);
    RUN_TEST(arrays);
    RUN_TEST(wait);

    END();
}
