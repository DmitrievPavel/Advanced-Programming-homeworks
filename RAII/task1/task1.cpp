
#include <iostream>

class smart_array {

private:
    int* ptr;
    int size_;
    int count;

public:
    smart_array(int size) {
        size_ = size;
        ptr = new int[size];
        count = 0;
    }

    ~smart_array() {
        delete[] ptr;
    }

    void add_element(int a) {
        if (count >= size_) {
            throw std::length_error("Oversize");
        }
        ptr[count] = a;
        count++;
    }

    int get_element(int i) {
        if (i < 0 || i >= count) {
            throw std::out_of_range("Incorrect_index");
        }
        return ptr[i];
    }
};

int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
       // arr.add_element(10);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

