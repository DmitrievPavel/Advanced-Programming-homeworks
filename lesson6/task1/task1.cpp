

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void unique(std::vector<T>& vec) {

    std::sort(vec.begin(), vec.end());
    auto it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());

}

int main()
{
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
    unique(vec);
    std::cout << std::endl;
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
}

