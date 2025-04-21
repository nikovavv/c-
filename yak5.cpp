#include <iostream>
#include <cmath>
using namespace std;
class const WrongTriangleSideException {};
class Triangle {
    public:
        double a,b,c;
        bool exst_tr() {
            if (a == 0 || b == 0 || c == 0) return false; 
            return (a + b > c) && (a + c > b) && (b + c > a);
        }
        void show(){
            cout << "A = "<< a << ", B = "<< b << ", C = "<< c << endl;
        }
        double perimetr(){
            return a+b+c;
        }
        double square(){
            double pp = perimetr() / 2;
            return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
        }
        Triangle(double a1, double b1, double c1){
            a = a1;
            b = b1;
            c = c1;
            if (!exst_tr()){
                throw WrongTriangleSideException();
            }
        }
};
