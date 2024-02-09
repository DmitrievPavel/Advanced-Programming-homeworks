
#include <iostream>
#include <set>

int main()
{
    int count = 0;
    int size = 0;
    std::cout << "input size: ";
    std::cin >> size;
    std::set <int, std::greater <int>> myset;

    while (count < size) {
        int x = 0;
        std::cout << "input elem: ";
        std::cin >> x;
        myset.insert(x);
        count++;
    }

    std::cout << "output elem: \n";
    for (const auto& i : myset) {
        std::cout << i << std::endl;
    }
}


