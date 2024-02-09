

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

bool sor(const std::pair<char, int>& a, const std::pair <char, int>& b) {
    return a.second > b.second;
}

int main()
{
    std::string s = { "Hello World!!" };
    std::map<char, int> m;
    for (char i : s) {
        ++m[i];
    }
    std::vector <std::pair<char, int>> vec(m.begin(), m.end());
    std::sort(vec.begin(), vec.end(), sor);
    for (const auto& i : vec) {
        std::cout << i.first << ":" << i.second << std::endl;
    }

}
