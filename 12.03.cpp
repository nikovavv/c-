#include <iostream>
#include <set>
using namespace std;

// Класс положительной обыкновенной дроби
class Fraction {
private:
    int a; // Числитель дроби
    int b; // Знаменатель дроби

    // Функция нахождения наибольшего общего делителя (НОД)
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

public:
    // Конструктор по умолчанию: a = 0, b = 1
    Fraction() : a(0), b(1) {}

    // Конструктор дроби
    Fraction(int a, int b) {
        if (b == 0) {
            throw runtime_error("Знаменатель не может быть нулевым.");
        }

        // Если числитель больше знаменателя, оставляем только дробную часть
        if (a >= b) {
            int wholePart = a / b;
            int remainder = a % b;
            if (remainder == 0) {
                this->a = 0;
                this->b = 1;
            } else {
                this->a = remainder;
                this->b = b;
            }
        } else {
            this->a = a;
            this->b = b;
        }

        // Сокращение дроби
        int commonDivisor = gcd(this->a, this->b);
        this->a /= commonDivisor;
        this->b /= commonDivisor;
    }

    // Метод вывода дроби на экран
    void print() {
        cout << a << "/" << b << endl;
    }

    friend bool operator<(const Fraction& f1, const Fraction& f2) {
        return (f1.a * f2.b) < (f2.a * f1.b);
    }

    friend bool operator==(const Fraction& f1, const Fraction& f2) {
        return (f1.a * f2.b) == (f2.a * f1.b);
    }
    // Вспомогательная функция для нахождения наименьшего общего кратного
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    // Метод сложения двух дробей
    Fraction add(const Fraction& other) const {
        int commonMultiple = lcm(int b,int other.b); // Наименьшее общее кратное знаменателей
        int newA = a * (commonMultiple / b) + other.a * (commonMultiple / other.b);
        return Fraction(newA, commonMultiple);
    }
};

// Класс множества обыкновенных дробей
class SetOfFractions {
private:
    std::set<Fraction> fractions; // Множество дробей

public:
    // Метод, возвращающий true в случае, если множество пустое и false в противном случае
    bool isEmpty() {
        return fractions.empty();
    }

    // Метод добавления дроби в множество
    void append(Fraction a) {
        fractions.insert(a);
    }

    // Метод, исключающий дробь из множества
    void exclude(Fraction a) {
        fractions.erase(a);
    }
    // Метод, возвращающий сумму всех дробей в множестве
    Fraction sum() {
        if (isEmpty()) {
            return Fraction(0, 1); // Если множество пустое, возвращаем 0/1
        }

        Fraction result(0, 1);
        for (const auto& f : fractions) {
            result = result.add(f);
        }
        return result;
    }
};
