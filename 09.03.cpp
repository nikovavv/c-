// #include <iostream>
// #include <cmath>
// using namespace std;
// class Figure {
// public:
//     virtual double square() = 0;
//     virtual ~Figure() {}
// };

// class Triangle : public Figure {
// private:
//     double a, b, c;
// public:
//     Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

//     double square() override {
//         double s = (a + b + c) / 2;
//         return sqrt(s * (s - a) * (s - b) * (s - c));
//     }
// };

// class Rectangle : public Figure {
// private:
//     double a, b;
// public:
//     Rectangle(double a, double b) : a(a), b(b) {}

//     double square() override {
//         return a * b;
//     }
// };

// class Trapezoid : public Figure {
// private:
//     double a, b, h;
// public:
//     Trapezoid(double a, double b, double h) : a(a), b(b), h(h) {}

//     double square() override {
//         return ((a + b) / 2) * h;
//     }
// };

// int main() {
//     Figure* figures[] = {
//         new Triangle(3, 4, 5),
//         new Rectangle(4, 6),
//         new Trapezoid(3, 5, 4)
//     };

//     for (Figure* fig : figures) {
//         cout << "Площадь: " << fig->square() << std::endl;
//     }

//     for (Figure* fig : figures) {
//         delete fig;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;
void SendBK(const string& id, const string& message) {
    cout << "Send '" << message << "' to BK user " << id << endl;
}

void SendTelegraph(const string& login, const string& message) {
    cout << "Send '" << message << "' to Telegraph user " << login << endl;
}


class NotifierBase {
public:
    virtual void notify(const string& message) = 0;
    virtual ~NotifierBase() {} 
};


class BKNotifier : public NotifierBase {
private:
    string id;

public:
    BKNotifier(const string& id) : id(id) {}

    void notify(const string& message) override {
        SendBK(id, message);
    }
};


class TelegraphNotifier : public NotifierBase {
private:
    string login;

public:
    TelegraphNotifier(const string& login) : login(login) {}

    void notify(const string& message) override {
        SendTelegraph(login, message);
    }
};
