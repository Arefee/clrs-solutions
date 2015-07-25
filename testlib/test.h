#ifndef TESTING_LIBRARY
#define TESTING_LIBRARY

#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>
#include <time.h>

static jmp_buf _on_failure;

typedef struct TestRunInfo
{
    const char*  current_test;
    const char*  current_file;
    unsigned int current_line;

    unsigned int failures;
    unsigned int runs;

    clock_t begin;
    clock_t end;

} TestRunInfo;

TestRunInfo run_info = {"", "", 0, 0, 0};

static void _run_test(const char* name, void (*code)())
{
    run_info.current_test = name;
    ++run_info.runs;

    if (setjmp(_on_failure))
    {
        ++run_info.failures;
    }
    else
    {
        code();
    }
}

static void _abort_test()
{
    longjmp(_on_failure, 1);
}

static void _report_assertion_error(const char* assertion_name)
{
    fprintf(stderr, "\n===================================================\n");

    fprintf(stderr, "FAIL %s: %s (%s:%d)",
            run_info.current_test,
            assertion_name,
            run_info.current_file,
            run_info.current_line);

    fprintf(stderr, "\n===================================================\n");
}

static int _report_results()
{
    fprintf(stderr, "\n---------------------------------------------------\n");

    fprintf(stderr, "Ran %d test(s) in %.3fs\n\n",
            run_info.runs,
            (double)(run_info.end - run_info.begin) / (double)CLOCKS_PER_SEC);

    if (run_info.failures)
    {
        fprintf(stderr, "FAILED %d test(s)\n", run_info.failures);
        return EXIT_FAILURE;
    }
    else
    {
        fprintf(stderr, "OK\n");
        return EXIT_SUCCESS;
    }
}

#define TEST(name)                                                           \
    void _##name##_test_code()

#define BEGIN()                                                              \
    do                                                                       \
    {                                                                        \
        _SET_TIME(run_info.begin);                                           \
                                                                             \
    } while (0)

#define RUN_TEST(name)                                                       \
    do                                                                       \
    {                                                                        \
        _run_test(#name, _##name##_test_code);                               \
                                                                             \
    } while (0)

#define END()                                                                \
    do                                                                       \
    {                                                                        \
        _SET_TIME(run_info.end);                                             \
        return _report_results();                                            \
                                                                             \
    } while (0)

#define _SET_TIME(TIME)                                                      \
    TIME = clock();                                                          \
                                                                             \
    if (TIME == (clock_t) -1)                                                \
    {                                                                        \
        fprintf(stderr, "clock error: %s\n", #TIME);                         \
        exit(EXIT_FAILURE);                                                  \
    }

#define ASSERT_TRUE(COND)                                                    \
    do                                                                       \
    {                                                                        \
        run_info.current_file = __FILE__;                                    \
        run_info.current_line = __LINE__;                                    \
                                                                             \
        if (!(COND))                                                         \
        {                                                                    \
            _report_assertion_error(#COND " is not true");                   \
            _abort_test();                                                   \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_FALSE(COND)                                                   \
    do                                                                       \
    {                                                                        \
        run_info.current_file = __FILE__;                                    \
        run_info.current_line = __LINE__;                                    \
                                                                             \
        if ((COND))                                                          \
        {                                                                    \
            _report_assertion_error(#COND " is not false");                  \
            _abort_test();                                                   \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_EQUAL(GOT, EXP)                                               \
    do                                                                       \
    {                                                                        \
        run_info.current_file = __FILE__;                                    \
        run_info.current_line = __LINE__;                                    \
                                                                             \
        if ((GOT) != (EXP))                                                  \
        {                                                                    \
            _report_assertion_error(#GOT " != " #EXP);                       \
            _abort_test();                                                   \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_ALMOST_EQUAL(GOT, EXP, PLACES)                                \
    do                                                                       \
    {                                                                        \
        run_info.current_file = __FILE__;                                    \
        run_info.current_line = __LINE__;                                    \
                                                                             \
        if (fabs((EXP) - (GOT)) >= 1e-##PLACES)                              \
        {                                                                    \
            _report_assertion_error(#GOT " != " #EXP                         \
                                    " within " #PLACES " places");           \
            _abort_test();                                                   \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_STRING_EQUAL(GOT, EXP)                                        \
    do                                                                       \
    {                                                                        \
        run_info.current_file = __FILE__;                                    \
        run_info.current_line = __LINE__;                                    \
                                                                             \
        if (strcmp(GOT, EXP) != 0)                                           \
        {                                                                    \
            _report_assertion_error(#GOT " != " #EXP);                       \
            _abort_test();                                                   \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_ARRAY_EQUAL(GOT, EXP)                                         \
    do                                                                       \
    {                                                                        \
        run_info.current_file = __FILE__;                                    \
        run_info.current_line = __LINE__;                                    \
                                                                             \
        size_t length_of_GOT = sizeof (GOT) / sizeof (GOT)[0];               \
        size_t length_of_EXP = sizeof (EXP) / sizeof (EXP)[0];               \
                                                                             \
        if (length_of_GOT != length_of_EXP)                                  \
        {                                                                    \
            char error_message[70];                                          \
                                                                             \
            snprintf(error_message, 70,                                      \
                     "the size of '%s' is %zu, "                             \
                     "while the size of '%s' is %zu",                        \
                     #GOT, length_of_GOT, #EXP, length_of_EXP);              \
                                                                             \
            _report_assertion_error(error_message);                          \
            _abort_test();                                                   \
        }                                                                    \
                                                                             \
        for (size_t i = 0; i < length_of_GOT; ++i)                           \
        {                                                                    \
            if ((GOT)[i] != (EXP)[i])                                        \
            {                                                                \
                char error_message[100];                                     \
                                                                             \
                snprintf(error_message, 100,                                 \
                         "%s[%zu] != %s[%zu]",                               \
                         #GOT, i, #EXP, i);                                  \
                                                                             \
                _report_assertion_error(error_message);                      \
                _abort_test();                                               \
            }                                                                \
        }                                                                    \
                                                                             \
    } while (0)

#endif
