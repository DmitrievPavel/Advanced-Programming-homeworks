#include <iostream>
#include <vector>

template <class T>
void move_vectors(std::vector<T>& l, std::vector<T>& r) {
    r = std::move(l);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << "one: ";
    for (auto& i : one) {
        std::cout << i << "\t";
    }
    std::cout << "\ntwo: ";
    for (auto& i : two) {
        std::cout << i << "\t";
    }

    move_vectors(one, two);

    std::cout << "\none: ";
    for (auto& i : one) {
        std::cout << i << "\t";
    }
    std::cout << "\ntwo: ";
    for (auto& i : two) {
        std::cout << i << "\t";
    }
}

