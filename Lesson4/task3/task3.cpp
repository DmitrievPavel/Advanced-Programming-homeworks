

#include <iostream>
#include <vector>

class counter {
private:
    std::vector<int> vec;
    int sum;
    int count;
public:
    counter(std::vector<int> a) {
        vec = a;
        sum = 0;
        count = 0;
    }
    void operator()() {
        for (auto i : vec) {
            sum += i;
            if (i % 3 == 0) {
                count++;
            }
        }
    }
    int get_sum() {
        return sum;
    }
    int get_count() {
        return count;
    }
    void print() {
        for (auto i : vec) {
            std::cout << i << " ";
        }
    }
};

int main()
{
    std::vector<int> v = { 4, 1, 3, 6, 25, 54 };
    counter c(v);
    c.print();
    c();
    std::cout << "\nSum: " << c.get_sum() << "\nCount: " << c.get_count();

}


