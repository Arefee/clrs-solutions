#ifndef TESTING_LIBRARY
#define TESTING_LIBRARY

#include <chrono>
#include <cmath>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/*
 * This namespace consists of the state of the library that is used during
 * checks and the helper functions, i.e., functions that are not part of the
 * API (the API consists of macros only).
 */

namespace TestLib
{
    using namespace chrono;

    /*
     * State variables
     */

    string current_test;
    string current_file;
    unsigned int current_line {0};

    unsigned int failures {0};
    unsigned int runs     {0};

    steady_clock::time_point begin;
    steady_clock::time_point end;

    /*
     * Helper functions
     */

    void set_time(steady_clock::time_point& point)
    {
        point = steady_clock::now();
    }

    double elapsed_time()
    {
        return duration_cast<milliseconds>(end - begin).count() / 1000.0;
    }

    void report_failure(const string& error)
    {
        cout << "\n===================================================\n";

        cout << "FAIL " << current_test << ": " << error
             << " ("    << current_file << ':'  << current_line << ')';

        cout << "\n===================================================\n";
    }

    int report_results()
    {
        cout << "\n---------------------------------------------------\n"
             << "Ran " << runs << " test(s) in " << elapsed_time() << "s\n\n";

        if (failures)
        {
            cout << "FAILED " << failures << " test(s)\n";
            return 1;
        }
        else
        {
            cout << "OK\n";
            return 0;
        }
    }

    void run_test(const string& name, const function<void()>& code)
    {
        current_test = name;
        ++runs;

        try
        {
            code();
        }
        catch (const exception& error)
        {
            ++failures;
            report_failure(error.what());
        }
    }

    template <typename T>
    string to_string(const T& item)
    {
        ostringstream out;
        out << item;

        return out.str();
    }
}

/*
 * Essentially this is the library API
 */

#define TEST(name)                                                           \
    void _##name##_test_code()

#define RUN_TEST(name)                                                       \
    do                                                                       \
    {                                                                        \
        TestLib::run_test(#name, _##name##_test_code);                       \
                                                                             \
    } while (0)

#define BEGIN()                                                              \
    do                                                                       \
    {                                                                        \
        TestLib::set_time(TestLib::begin);                                   \
                                                                             \
    } while (0)

#define END()                                                                \
    do                                                                       \
    {                                                                        \
        TestLib::set_time(TestLib::end);                                     \
        return TestLib::report_results();                                    \
                                                                             \
    } while (0)

#define ASSERT_TRUE(COND)                                                    \
    do                                                                       \
    {                                                                        \
        TestLib::current_file = __FILE__;                                    \
        TestLib::current_line = __LINE__;                                    \
                                                                             \
        if (!(COND))                                                         \
        {                                                                    \
            throw logic_error {TestLib::to_string((COND)) + " is not true"}; \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_FALSE(COND)                                                   \
    do                                                                       \
    {                                                                        \
        TestLib::current_file = __FILE__;                                    \
        TestLib::current_line = __LINE__;                                    \
                                                                             \
        if ((COND))                                                          \
        {                                                                    \
            throw logic_error {TestLib::to_string((COND)) + " is not false"};\
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_EQUAL(GOT, EXP)                                               \
    do                                                                       \
    {                                                                        \
        TestLib::current_file = __FILE__;                                    \
        TestLib::current_line = __LINE__;                                    \
                                                                             \
        if ((GOT) != (EXP))                                                  \
        {                                                                    \
            throw logic_error {TestLib::to_string((GOT)) +                   \
                               " != " +                                      \
                               TestLib::to_string((EXP))};                   \
        }                                                                    \
                                                                             \
    } while (0)

#define ASSERT_ALMOST_EQUAL(GOT, EXP, PLACES)                                \
    do                                                                       \
    {                                                                        \
        TestLib::current_file = __FILE__;                                    \
        TestLib::current_line = __LINE__;                                    \
                                                                             \
        if (fabs((EXP) - (GOT)) >= 1e-##PLACES)                              \
        {                                                                    \
            throw logic_error {TestLib::to_string((GOT)) +                   \
                               " != " +                                      \
                               TestLib::to_string((EXP)) +                   \
                               " within " +                                  \
                               TestLib::to_string((PLACES)) +                \
                               " places"};                                   \
        }                                                                    \
                                                                             \
    } while (0)

/*
 * Definitions of the `<<` operator for several containers. Those are used when
 * an assertion consisting of such objects fails and they have to be displayed.
 */

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& items)
{
    out << '[';

    for (auto i = items.cbegin(); i != items.cend(); ++i)
    {
        out << *i;

        if (i + 1 != items.cend())
        {
            out << ", ";
        }
    }

    out << ']';

    return out;
}

template <typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& items)
{
    out << '{';

    for (auto i = items.cbegin(); i != items.cend(); )
    {
        out << i->first << ": " << i->second;

        if (++i != items.cend())
        {
            out << ", ";
        }
    }

    out << '}';

    return out;
}

#endif
