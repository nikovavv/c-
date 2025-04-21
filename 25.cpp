//Никонорова Варвара Алексеевна ЭФБО-01-24
#include <iostream>
#include <math.h>
using namespace std;
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Spiral : public Shape {
private:
    double a, b;
    const double PI = acos(-1.0);
public:
    Spiral(double a, double b) : a(a), b(b) {}

    double area() override {
        return PI * a * a + 2 * PI * PI * a * b + (4 * PI * PI * PI * b * b) / 3;
    }
};
int main() {
    Spiral mySpiral(1.0, 0.1);
    Shape* shapeSp= &mySpiral;
    cout << "Площадь спирали: " << shapeSp->area() << endl;
    return 0;
}