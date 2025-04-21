#include <iostream>
#include <vector>
using namespace std;
class BinaryHeap {
    private:
        vector<int> heap;
        //для max-кучи        
        void heapifyDown(int index) {
            int size = heap.size();
            while (2 * index +1 < size) {
                int left = 2*index +1;
                int right =2*index +2;
                int parent = index;
                // Проверяем, является ли левый потомок наибольшим
                if (left <size && heap[left]> heap[parent]){
                    parent = left;
                }
                // Проверяем, является ли правый потомок наибольшим
                if (right <size && heap[right]> heap[parent]){
                    parent = right;
                }
                if (parent != index){
                    swap(heap[index],heap[parent]);
                    index = parent;
                }else{
                    break;
                }
                }
        }
        //восстановление структуры кучи после вставки
        void heapifyUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap[index] > heap[parent]) {
                    swap(heap[index], heap[parent]);
                    index = parent;
                } else {
                    break;
                }
            }
        }
    public:
        //создание пустой кучи
        BinaryHeap(){}    
        //построение max-кучи из массива
        BinaryHeap(vector<int>&arr){
            heap = arr;
            for (int i = heap.size() / 2 - 1; i >= 0;i--){
                heapifyDown(i);
            }
        }
        //макс элемент
        int getMax(){
            if (heap.empty()){
                cerr <<"куча пустая\n";
                return -1;
            }
            return heap[0];
        }
        //удаление макс элемента
        int deleteMax(){
            if (heap.empty()){
                cerr <<"куча пустая\n";
                return -1;
            }
            int maxx = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
            return maxx;
        }
        // Вставка элемента в кучу
        void insert(int value) {
            heap.push_back(value);
            heapifyUp(heap.size() - 1);
        }
        // Вывод содержимого кучи
        void printHeap() {
            for (int val : heap)
                cout << val << " ";
            cout << endl;
        }
};  


int main() {
    vector<int> arr = {10,20,5,30,2};
    cout <<"Исходный массив: ";
    for (int num :arr) cout << num<<" ";
    cout <<endl;
    BinaryHeap Heap(arr);
    cout << "Куча после построения: ";
    Heap.printHeap();
    //добавление элемента
    Heap.insert(15);
    cout << "Куча после вставки: ";
    Heap.printHeap(); 
    //поиск максимума
    cout <<"Максимальный элемент: "<<Heap.getMax()<<endl;
    //удаление максимума
    cout<<"Куча после удаления: ";
    Heap.deleteMax();
    Heap.printHeap();
    return 0;
}
