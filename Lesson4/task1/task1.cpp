
#include <iostream>
#include <vector>

template <class T>

T pow(T a) {
    return a * a;
}

template <>

std::vector<int> pow(std::vector<int> a) {

    for (int i = 0; i < a.size(); ++i) {
        a[i] *= a[i];
    }

    return a;
}

int main()
{
    int a = 4;

    std::cout << "[IN] " << a << "\n[OUT] " << pow(a) << std::endl;

    std::vector<int> vec = { -1, 4, 8 };

    std::cout << "[IN] ";

    for (int i : vec) {
        std::cout << i << " ";
    }

    std::cout << "\n[OUT] ";

    for (int i : pow(vec)) {
        std::cout << i << " ";
    }

}

