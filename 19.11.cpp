

#include <iostream>
using namespace std;
const int maxx = 100; // максимальный размер массива для хранения комбинации

void Combinations(int n, int start, int a[], int index) {
    if (n == 0) { // Если сумма равна 0, выводим текущую комбинацию
        for (int i = 0; i < index; ++i) {
            cout << a[i] << (i == index - 1 ? "\n" : " ");
        }
        return;
    }
    for (int i = start; i <= n; ++i) {
        a[index] = i; // добавляем число в текущую комбинацию
        Combinations(n - i, i, a, index + 1); //рекурсия для оставшихся чисел суммы
    }
}
int main() {
    int n;
    cout << "Введите число n: ";
    cin >> n;
    int a[maxx]; // Массив для хранения текущей комбинации
    cout << "комбинации чисел, дающие в сумме " << n << ":\n";
    Combinations(n, 1, a, 0);
    return 0;
}