//1
#include <iostream>
using namespace std;

long double power(long double a,int n){
    if (n==1){
        return a;
    }else{
        long double res = power(a,n / 2);
        if (n%2==0){
            return res*res;
        }else{
            return res*res*a;
        }
    }
}
int main() {
    int b;
    long double a;
    cin >>a>>b;
    cout <<power(a,b)<<endl;
    return 0;
}




//2
#include <iostream>
using namespace std;

int nod(int a, int b){
    if ((a==0)||(b==0)){
        return a+b;
    }
    return nod(b,a%b);
}
    
int main() {
    int a,b;
    cin >>a>>b;
    cout <<nod(a,b)<<endl;
    return 0;
}


//3
#include <iostream>
using namespace std;
void salfetki(int n, int a, int b, int c) {
    if (n == 1) {
        cout << "Ingredient 1 move from " << a << " to " << b << endl;
        return;
    }
    salfetki(n - 1, a, c, b); 
    cout << "Ingredient " << n << " move from " << a << " to " << b << endl; 
    salfetki(n - 1, c, b, a); 
}
int main() {
    int n;
    cout << "Введите количество ингредиентов: ";
    cin >> n;
    salfetki(n, 1, 3, 2);
    return 0;
}








































































































