
#include <iostream>

template <class T>
class Unique_ptr {
private:
    T* ptr;
public:

    Unique_ptr(T* raw_ptr) {
        ptr = raw_ptr;
    }

    Unique_ptr(const Unique_ptr& other) = delete;

    Unique_ptr& operator=(const Unique_ptr& other) = delete;

    ~Unique_ptr() {
        delete ptr;
        if (ptr != nullptr) {
            std::cout << "destructed\n";
        }
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* release() {
        T* raw_ptr = ptr;
        ptr = nullptr;
        return raw_ptr;
    }
};

class Testclass {
public:
    int val1;
    int val2;
    Testclass(int v1, int v2) {
        val1 = v1;
        val2 = v2;
    }
};



int main()
{
    Testclass* ptr = new Testclass(1, 2);
    Unique_ptr<Testclass> u_ptr (ptr);

    std::cout << (*u_ptr).val1 << ", " << (*u_ptr).val2 << std::endl;
    std::cout << u_ptr->val1 << ", " << u_ptr->val2 << std::endl;

    auto raw_ptr = u_ptr.release();
    delete raw_ptr;
}

