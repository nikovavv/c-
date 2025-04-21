#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
    public:
        double a,b,c;
        bool exst_tr(){
            if (a == 0 || b == 0 || c == 0){
                return false;
            }
        }
        void set(double a1, double b1, double c1){
            a = a1;
            b = b1;
            c = c1;
        }
        void show(){
            cout << "A = "<< a << ",B = "<< b << ",C = "<< c << endl;
        }
        double perimetr(){
            return a+b+c;
        }
        double square(){
            double pp = perimetr() / 2;
            return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
        }
};
int main() {
    double a,b,c;
    cin >> a >> b >> c;
    
    Triangle T;
    T.set(a, b, c);
    cout << "Perimeter: " << T.perimetr() << endl;
    cout << "Area: " << T.square() << endl;
    
    return 0;
}