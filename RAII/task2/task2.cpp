
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

    smart_array& operator=(smart_array& other) {

        std::swap(ptr, other.ptr);

        return *this;
    }
};

int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
        std::cout << arr.get_element(0) << ", " << arr.get_element(1);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}


