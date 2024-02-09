
#include <iostream>

template <class T>
class Myvector {

private:
    T* ptr;
    size_t logic_size;
    size_t actual_size;

public:

    Myvector() {
        logic_size = 1;
        actual_size = 0;
        ptr = new T[logic_size];
    }

    ~Myvector() {
        delete[] ptr;
    }

    T at(size_t i) {
        if (i >= actual_size) {
            throw std::out_of_range("Incorrect_index");
        }
        return ptr[i];
    }

    void push_back(T value) {
        if (actual_size == logic_size) {
            logic_size *= 2;
            T* tmp = new T[logic_size];
            for (int i = 0; i < actual_size; ++i) {
                tmp[i] = ptr[i];
            }
            delete[] ptr;
            ptr = tmp;
        }
        ptr[actual_size] = value;
        ++actual_size;
    }

    size_t size() {
        return actual_size;
    }

    size_t capacity() {
        return logic_size;
    }
};

int main()
{
    Myvector<double> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0.25);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }

}


