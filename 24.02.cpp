// #include <iostream>
// #include <ctime>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// // Функция для создания нового узла
// Node* createNode(int value) {
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->left = nullptr; //левый потомок пока 0
//     newNode->right = nullptr; //правый потомок пока 0
//     return newNode;
// }

// // Функция для добавления элемента в дерево
// Node* insert(Node* root, int value) {
//     if (!root) {
//         return createNode(value); // Если дерево пустое, создаем корень
//     }
//     if (value < root->data) {
//         root->left = insert(root->left, value); // Вставка в левое поддерево
//     } else {
//         root->right = insert(root->right, value); // Вставка в правое поддерево
//     }
//     return root;
// }

// // Прямой обход дерева (preorder)
// void preorder(Node* root) {
//     if (root) {
//         cout << root->data << " "; // Посетить корень
//         preorder(root->left); // Обход левого поддерева
//         preorder(root->right); // Обход правого поддерева
//     }
// }

// // Вычисление глубины дерева
// int Height(Node* root) {
//     if (!root) return 0;
//     int leftHeight = Height(root->left);
//     int rightHeight = Height(root->right);
//     return max(leftHeight, rightHeight) + 1;
// }

// // Поиск элемента в дереве
// bool search(Node* root, int key) {
//     if (!root) return false;
//     if (root->data == key) return true; // Если значение в текущем узле равно искомому, элемент найден
//     if (key < root->data) return search(root->left, key); // Если искомое значение меньше, чем значение в текущем узле то ищем в левом поддереве 
//     return search(root->right, key);
// }

// // Функция для нахождения минимального узла в дереве
// Node* findMin(Node* root) {
//     while (root->left) root = root->left; //ищем самый левый узел
//     return root;
// }

// // Удаление узла из дерева
// Node* deleteNode(Node* root, int key) {
//     if (!root) return nullptr;
//     if (key < root->data) {
//         root->left = deleteNode(root->left, key); // Ищем узел для удаления в левом поддереве
//     } else if (key > root->data) {
//         root->right = deleteNode(root->right, key); // Ищем узел для удаления в правом поддереве
//     } else { // когда нашли узел который нужно удалить
//         // Узел с одним или без потомков
//         if (!root->left) { //если нет левого потомка
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         } else if (!root->right) { //если нет правого потомка 
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         }
//         // Если это узел с двумя потомками
//         Node* temp = findMin(root->right);
//         root->data = temp->data;  // Заменяем данные текущего узла данными минимального узла из правого поддерева
//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }

// int main() {
//     srand(time(0));
//     Node* root = nullptr;
//     int n;
//     cout << "Введите количество элементов: ";
//     cin >> n;

//     cout << "Случайные элементы дерева: ";
//     for (int i = 0; i < n; i++) {
//         int value = rand() % 100 + 1; // Генерация случайного числа от 1 до 100
//         cout << value << " ";
//         root = insert(root, value);
//     }
//     cout << endl;

//     cout << "Прямой обход: ";
//     preorder(root);
//     cout << endl;

//     cout << "Глубина дерева: " << Height(root) << endl;

//     // Поиск элемента
//     int key;
//     cout << "Введите число для поиска: ";
//     cin >> key;
//     if (search(root, key)) {
//         cout << "Элемент найден!" << endl;
//     } else {
//         cout << "Элемент не найден!" << endl;
//     }

//     cout << "Введите число для удаления: ";
//     cin >> key;
//     root = deleteNode(root, key);
    
//     cout << "Дерево после удаления: ";
//     preorder(root);
//     cout << endl;

//     return 0;
// }


#include <iostream> 
#include <vector> 
using namespace std;

// Структура для  интервала
struct Interval {
    int start; // Начало интервала
    int end;   // Конец интервала
};

// Структура для узла дерева отрезков
struct TreeNode {
    Interval interval; // Интервал, представленный этим узлом
    TreeNode* left;  // Левый потомок
    TreeNode* right; // Правый потомок
};

// Функция для создания нового узла 
TreeNode* createNode(Interval interval) {
    TreeNode* newNode = new TreeNode; 
    newNode->interval = interval; // Устанавливаем интервал для нового узла
    newNode->left = nullptr;               
    newNode->right = nullptr;
    return newNode; // Возвращаем указатель на новый узел
}

// построение дерева отрезков
TreeNode* build(int l, int r) {
    // если интервал состоит только из одного элемента
    if (l == r) {
        Interval interval = {l, r}; // Создаем интервал 
        return createNode(interval);  // Создаем листовой узел для этого интервала
    }
    int mid = l + (r - l) / 2;
    // Создаем текущий узел
    Interval interval = {l, r}; // Интервал для текущего узла
    TreeNode* node = createNode(interval);  
    // Рекурсивно строим левое и правое поддеревья
    node->left = build(l, mid);    // Левое поддерево 
    node->right = build(mid + 1, r); // Правое поддерево 
    return node;  // Возвращаем созданный узел
}

// Функция для симметричного обхода дерева отрезков и вывода элементов
void symmetry(TreeNode* root) {
    if (root != nullptr) {
        symmetry(root->left); // Обходим левое поддерево
        cout << "[" << root->interval.start << ", " << root->interval.end << "] "; // Посещаем узел и выводим его интервал
        symmetry(root->right); // Обходим правое поддерево
    }
}

// Функция для подсчета количества интервалов в дереве, содержащих точку X
int countInterval(TreeNode* root, int x) {
    if (root == nullptr) {
        return 0;  
    }
    // Если текущий интервал содержит точку X
    if (x >= root->interval.start && x <= root->interval.end) {
        return 1 + countInterval(root->left, x) + countInterval(root->right, x);
    } else if (x < root->interval.start) {   // проверяем левое поддерево
        return countInterval(root->left, x);
    } else {  //проверяем правое поддерево
        return countInterval(root->right, x);
    }
}

int main() {
    int l, r;
    cout << "Введите начало интервала (l): ";
    cin >> l;
    cout << "Введите конец интервала (r): ";
    cin >> r;
    TreeNode* root = build(l, r);
    cout << "Симметричный обход дерева отрезков: ";
    symmetry(root);
    cout << endl;

    // Подсчитываем количество интервалов, содержащих точку X
    int x;
    cout << "Введите точку X для подсчета интервалов ";
    cin >> x;
    int count = countInterval(root, x);
    cout << "Количество интервалов, содержащих точку " << x << ": " << count << endl;

    return 0;
}