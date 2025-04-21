// #include <iostream>
// using namespace std;
// struct Node {
//     int data;          // Данные узла
//     Node* next;        // Указатель на следующий узел
//     Node* prev;        // Указатель на предыдущий узел
// }
// void append(Node** head_ref,int new_data){ //функция для добавления узла в конец списка
//     Node* new_node = new Node(); //создаем новый узел
//     Node* last = *head_ref; //указатель на последний узел
//     new_node->data = new_data; //заполняем данные нового узла
//     new_node->next = NULL; //следующий узел будет NULL
//     if (*head_ref == NULL){
//         new_node->prev = nullptr; //предыдущий узел будет NULL
//         *head_ref = new_node; //новый узел становится головой списка
//     }
//     while (last->next != NULL){ //находим последний узел
//         last = last->next;
//     }



// }
// int main(){

//     return 0;
// }
// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
    public:
        double a,b,c;
        bool exst_tr(){
            if (a == 0 || b == 0 || c == 0) &&((a+b)>c && (a+c)>b && (b+c)>a)){
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
}
int main() {
    double a,b,c;
    cin >> a >> b >> c;
    
    Triangle T;
    T.set(a, b, c);
    cout << "Perimeter: " << T.perimetr() << endl;
    cout << "Area: " << T.square() << endl;
    
    return 0;
}