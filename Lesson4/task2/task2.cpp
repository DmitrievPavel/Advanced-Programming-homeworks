

#include <iostream>

template <class T>
class table {
private:

    T** ptr;
    size_t rows_;
    size_t cols_;

public:

    table(size_t rows, size_t cols) {

        rows_ = rows;
        cols_ = cols;
        ptr = new T*[rows_];
        for (int i = 0; i < rows_; ++i) {
            ptr[i] = new T[cols_];
        }
    }

    ~table() {

        for (int i = 0; i < rows_; ++i) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }

    int size() const {
        return rows_ * cols_;
    }

    T* operator[](const size_t index) {

        if (index >= rows_ || index >= cols_) {
            throw std::out_of_range("Incorrect_index");
        }
        return ptr[index];
    }

    const T* operator[](const size_t index) const {

        if (index >= rows_ || index >= cols_) {
            throw std::out_of_range("Incorrect_index");
        }
        return ptr[index];
    }
};

int main()
{
    try {
        auto test = table<int>(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0];
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}


