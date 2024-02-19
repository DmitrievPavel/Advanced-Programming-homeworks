
#include <iostream>
#include <string>


class big_integer {
private:
    std::string big_int;

public:
    big_integer(std::string Big_int) : big_int(Big_int) {};

    big_integer(big_integer&& other) noexcept {                                             //конструктор перемещения 
        big_int = other.big_int;
        other.big_int.clear();
    }

    big_integer& operator=(big_integer&& other) noexcept {                                  //перемещающий оператор присваивания
        big_int = other.big_int;
        other.big_int.clear();
    }

    big_integer operator+(const big_integer& other) const {                                 //оператор сложения двух больших чисел
        return big_integer(std::to_string(std::stoi(big_int) + std::stoi(other.big_int)));
    }

    big_integer operator-(const big_integer& other) const {                                 //оператор вычитания двух больших чисел
        return big_integer(std::to_string(std::stoi(big_int) - std::stoi(other.big_int)));
    }

    big_integer operator*(const big_integer& other) const {                                 //оператор умножения двух больших чисел
        return big_integer(std::to_string(std::stoi(big_int) * std::stoi(other.big_int)));  
    }

    big_integer operator/(const big_integer& other) const {                                 //оператор деления двух больших чисел
        return big_integer(std::to_string(std::stold(big_int) / std::stold(other.big_int)));
    }

    big_integer operator+(const int num) const {                                           //оператор сложения с числом
        return big_integer(std::to_string(std::stoi(big_int) + num));
    }

    big_integer operator-(const int num) const {                                           //оператор вычитания числа
        return big_integer(std::to_string(std::stoi(big_int) - num));
    }

    big_integer operator*(const int num) const {                                           //оператор умножения на число
        return big_integer(std::to_string(std::stoi(big_int) * num));
    }

    big_integer operator/(const int num) const {                                           //оператор деления на число
        return big_integer(std::to_string(std::stold(big_int) / num));
    }

    std::string get_str() const {
        return big_int;
    }
};

big_integer operator+(const int num, const big_integer& other) {                           //оператор сложения числа и большого числа
    return big_integer(std::to_string(num + std::stoi(other.get_str())));
}

big_integer operator-(const int num, const big_integer& other) {                           //оператор вычитания числа и большого числа
    return big_integer(std::to_string(num - std::stoi(other.get_str())));
}

big_integer operator*(const int num, const big_integer& other) {                           //оператор умножения числа на большое число
    return big_integer(std::to_string(num * std::stoi(other.get_str())));
}

big_integer operator/(const int num, const big_integer& other) {                           //оператор деления числа на большое число
    return big_integer(std::to_string(num / std::stold(other.get_str())));
}

std::ostream& operator<<(std::ostream& stream, const big_integer& big_int) {               //оператор вывода
    stream << big_int.get_str();
    return stream;
}

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("-78524");
    auto res = number1 * number2;
    std::cout << res;

}


