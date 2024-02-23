
#include <iostream>
#include <vector>
#include <string>

class big_integer {
private:
    std::vector<int> num;
    bool negative_sign = false;
public:

    big_integer(std::string str) {                                              //конструктор для создания числа
        if (str[0] == '-') {
            negative_sign = true;
            for (int i = 0; i < str.size() - 1; i++) {
                num.push_back(str[(str.size() - i) - 1] - 48);
            }
        }
        else {
            for (int i = 0; i < str.size(); i++) {
                num.push_back(str[(str.size() - i) - 1] - 48);
            }
        }

        if (negative_sign) {
            for (int i = 0; i < str.size() - 1; i++) {
                num[i] *= -1;
            }
        }

    }

    big_integer(std::vector<int> vec) {                                        //конструктор для создания результата
        num = vec;
    }

    big_integer(big_integer&& other) noexcept {                                //конструктор перемещения
        num = std::move(other.num);
        negative_sign = other.negative_sign;
    }

    big_integer& operator=(big_integer&& other) noexcept {                     //перемещающий оператор присваивания
        num = std::move(other.num);
        negative_sign = other.negative_sign;
    }

    big_integer operator+(big_integer& other) {                                //сложение двух больших чисел
        std::vector<int> res;
        long long size = (num.size() > other.num.size()) ? num.size() : other.num.size();
        for (int i = 0; i < size; i++) {
            if (i == num.size()) {
                num.push_back(0);
            }
            if (i == other.num.size()) {
                other.num.push_back(0);
            }
            res.push_back(num[i] + other.num[i]);

        }
        for (int i = 0; i < size - 1; i++) {
            if (res[i] >= 10) {
                res[i] -= 10;
                res[i + 1]++;
            }
        }
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        if (negative_sign && other.negative_sign) {
            for (int i = 0; i < res.size() - 1; i++) {
                res[i] *= -1;
            }
        }
        return big_integer(res);
    }

    big_integer operator*(big_integer& other) {                                //умножение двух больших чисел
        std::vector<int> res;
        long long size = (num.size() > other.num.size()) ? num.size() * 2 : other.num.size() * 2;
        res.resize(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i; j++) {
                if (i == num.size() || j == num.size()) {
                    num.push_back(0);
                }
                if (i == other.num.size() || j == other.num.size()) {
                    other.num.push_back(0);
                }
                res[i + j] += num[i] * other.num[j];
            }
        }
        for (int i = 0; i < size - 1; i++) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        if (negative_sign && !other.negative_sign || other.negative_sign && !negative_sign) {
            for (int i = 0; i < res.size() - 1; i++) {
                res[i] *= -1;
            }
        }
        return big_integer(res);
    }

    big_integer operator*(long long dig) {                                   //умножение на число
        std::string tmp = std::to_string(dig);
        big_integer other(tmp);
        return *this * other;
    }

    std::vector<int> get_num() const {
        return num;
    }
};

std::ostream& operator<<(std::ostream& stream, const big_integer& obj) {
    auto res = obj.get_num();
    for (auto it = res.rbegin(); it != res.rend(); it++) {
        stream << *it;
    }
    return stream;
}

int main()
{
    auto num1 = big_integer("-1234567");
    auto num2 = big_integer("1224");
    auto res = num1 * num2;
    std::cout << res;
}


