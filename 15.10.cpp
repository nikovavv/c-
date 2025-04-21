//31

#include <iostream>
using namespace std;
void arraypro(int arr[],int n){  //процедура принимает массив и его размер
    for (int i = n-1; i >= 0; --i){
        cout << arr[i] << " ";   //выводятся элементы массива, начиная с последнего, без изменения массива
    }
    cout << endl;
}


int main() {
    int arr[] = {1,2,3,4,5};    //изначальный массив
    int n = sizeof(arr) / sizeof(int);    //узнаем размер массива
    cout << "Массив: ";
    for (int i=0; i<n;++i){ //выводим сам массив
        cout <<arr[i]<<" ";
    }
    cout << endl;
    cout << "Перевернутый массив: ";
    arraypro(arr,n); //выводим массив в обратном порядке

    return 0;
}