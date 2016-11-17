#include "MyString.h"
#include <utility>

int main()
{
    MyString s1("qwerty");
    MyString s2("ABC");
    MyString s3 = s2;

    MyString s4;
    s4 = s3;

    MyString::debugPrintCounters();

    std::cout << s1 << '\n'
              << s2 << '\n'
              << s3 << '\n'
              << s4 << "\n\n\n";

    s2 = s1;
    s1 = std::move(s3);

    MyString::debugPrintCounters();

    std::cout << s1 << '\n'
              << s2 << '\n'
              << s3 << '\n'
              << s4 << "\n\n\n";

    MyString::debugPrintCountersCount();
    s1 = "1";
    MyString::debugPrintCountersCount();
    s2 = "2";
    MyString::debugPrintCountersCount();
    s3 = "3";
    MyString::debugPrintCountersCount();
    s4 = "4";
    MyString::debugPrintCountersCount();
    MyString s5 = MyString("5");
    MyString::debugPrintCountersCount();
    MyString s6 = MyString(std::move(s4));
    MyString::debugPrintCountersCount();

    MyString::debugPrintCounters();

    std::cout << s1 << '\n'
              << s2 << '\n'
              << s3 << '\n'
              << s4 << '\n' << s5 << '\n' << s6 << "\n\n\n";

    return 0;
}
