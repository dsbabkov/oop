#include "list.h"
#include <fstream>

int main()
{
    List list;
    list.clear();


    list.append({{0,0}, 2});
    list.clear();
    list.append({{0,1}, 2});
    list.append({{0,0}, 2});
    list.append({{0,2}, 2});
    list.append({{0,0}, 2});
    list.append({{0,3}, 2});
    list.append({{0,0}, 1});

    list.prepend({{5,6}, 7});

    List list2;
    list2 = list;

    std::cout << list << "\n\n";
    std::cout << "Removed: " << list2.removeAll({{0,0}, 2}) << '\n'
              << list2;

    std::ofstream f("test.txt");
    f << list;

    return 0;
}

