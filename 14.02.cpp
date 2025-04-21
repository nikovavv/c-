// //5
// #include "iostream"
// #include <vector>

// using namespace std;

// class MyStack {
// private:
//     vector<int> stack;

// public:
//     void push(int n) {
//         stack.push_back(n);
//     }

//     void pop() {
//         if (!stack.empty()) {
//             cout << stack.back() << endl;
//             stack.pop_back();
//         } else {
//             cout << "Stack is empty" << endl;
//         }
//     }

//     void back() {
//         if (!stack.empty()) {
//             cout << stack.back() << endl;
//         } else {
//             cout << "Stack is empty" << endl;
//         }
//     }

//     void size() {
//         cout << stack.size() << endl;
//     }

//     void clear() {
//         stack.clear();
//     }
// };

// //4

// #include <iostream>
// #include <cmath>
// using namespace std;
// class Triangle {
// public:
//     double a, b, c;

//     Triangle(double a, double b, double c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;

//         if (!exst_tr()) {
//             this->a = 3;
//             this->b = 4;
//             this->c = 5;
//         }
//     }

//     bool exst_tr() {
//         return a != 0 && b != 0 && c != 0 && a + b > c && b + c > a && a + c > b;
//     }

//     void show() {
//         cout << "A = " << a << ", B = " << b << ", C = " << c << endl;
//     }

//     double perimetr() {
//         return a + b + c;
//     }

//     double square() {
//         double p = (a + b + c) / 2;
//         return sqrt(p * (p - a) * (p - b) * (p - c));
//     }

//     bool is_similar(Triangle &t2) {
//         double ka = a / t2.a;
//         double kb = b / t2.b;
//         double kc = c / t2.c;
//         return ka == kb && kb == kc;
//     }

//     double get_a() {
//         return a;
//     }

//     double get_b() {
//         return b;
//     }

//     double get_c() {
//         return c;
//     }
// };

// class Circle {
// public:
//     float r, x, y;

//     Circle(float r, float x, float y) {
//         this->r = r;
//         this->x = x;
//         this->y = y;
//     }

//     void set_circle(float r, float x, float y) {
//         this->r = r;
//         this->x = x;
//         this->y = y;
//     }

//     float square() {
//         return M_PI * r * r;
//     }

//     bool triangle_around(Triangle &t) {
//         double s = t.square();
//         if (s == 0) return false;
//         return r == (t.get_a() * t.get_b() * t.get_c()) / (4 * s);
//     }

//     bool triangle_in(Triangle &t) {
//         double s = t.square();
//         double p = t.perimetr() / 2;
//         if (p == 0) return false;
//         return r == s / p;
//     }

//     bool check_circle(Circle &c) {
//         double distance = sqrt(pow(c.x - x, 2) + pow(c.y - y, 2));
//         return distance < (r + c.r) && distance >= abs(r - c.r);
//     }
// };
// //3

// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// class Triangle {
//     public:
//         double a,b,c;
//         bool exst_tr() {
//             if (a == 0 || b == 0 || c == 0) return false; 
//             return (a + b > c) && (a + c > b) && (b + c > a);
//     }
//         void show(){
//             cout << "A = "<< a << ", B = "<< b << ", C = "<< c << endl;
//         }
//         double perimetr(){
//             return a+b+c;
//         }
//         double square(){
//             double pp = perimetr() / 2;
//             return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
//         }
//         Triangle(double a1, double b1, double c1){
//             a = a1;
//             b = b1;
//             c = c1;
//             if (!exst_tr()){
//                 a = 3;
//                 b = 4;
//                 c = 5;
//             }
//         }
//          bool is_similar(Triangle & t2){
//             double sides1[] = {a, b, c};
//             double sides2[] = {t2.a, t2.b, t2.c};
//             sort(sides1, sides1 + 3);
//             sort(sides2, sides2 + 3);
//             double ratio1 = sides1[0] / sides2[0];
//             double ratio2 = sides1[1] / sides2[1];
//             double ratio3 = sides1[2] / sides2[2];
//             const double tolerance = 1e-6; 
//             return (abs(ratio1 - ratio2) < tolerance) && (abs(ratio1 - ratio3) < tolerance);
//          }
// };
// //2

// #include <iostream>
// #include <cmath>
// using namespace std;
// class Triangle {
//     public:
//         double a,b,c;
//         bool exst_tr() {
//             if (a == 0 || b == 0 || c == 0) return false; 
//             return (a + b > c) && (a + c > b) && (b + c > a);
//     }
//         void show(){
//             cout << "A = "<< a << ", B = "<< b << ", C = "<< c << endl;
//         }
//         double perimetr(){
//             return a+b+c;
//         }
//         double square(){
//             double pp = perimetr() / 2;
//             return sqrt(pp * (pp - a) * (pp - b) * (pp - c));
//         }
//         Triangle(double a1, double b1, double c1){
//             a = a1;
//             b = b1;
//             c = c1;
//             if (!exst_tr()){
//                 a = 3;
//                 b = 4;
//                 c = 5;
//             }
//         }
// };
