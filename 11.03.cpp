// #include <iostream>
// using namespace std;

// // Структура узла двоичного дерева поиска
// struct Node {
//     int key;        // Значение узла
//     Node* left;     // Левый потомок
//     Node* right;    // Правый потомок
//     int balance;    // Баланс узла
// };

// // Функция создания нового узла с заданным балансом
// Node* createNode(int key, int balance, Node* left = nullptr, Node* right = nullptr) {
//     Node* node = new Node;
//     node->key = key;
//     node->left = left;
//     node->right = right;
//     node->balance = 0;
//     return node;
// }

// // Функция расчета высоты дерева
// int height(Node* node) {
//     if (node == nullptr) {
//         return 0;
//     }
//     return max(height(node->left), height(node->right)) + 1;
// }

// // Функция обновления баланса узла
// void node_balance(Node* node) {
//     if (node == nullptr) {
//         return;
//     }
//     node->balance = height(node->left) - height(node->right);
// }

// // Функция обновления баланса всех узлов дерева
// void allbalances(Node* node) {
//     if (node == nullptr) {
//         return;
//     }
//     allbalances(node->left);
//     allbalances(node->right);
//     node_balance(node);
// }

// // Функция симметричного (in-order) обхода дерева
// void inOrder(Node* root) {
//     if (root) {
//         inOrder(root->left);
//         cout << root->key << " (" << root->balance << ") ";
//         inOrder(root->right);
//     }
// }

// int main() {
//     // Создание двоичного дерева поиска
//     Node* root = createNode(30,createNode(20, createNode(10), createNode(25)),createNode(40, nullptr, createNode(50)));
//     allbalances(root);
//     // Вывод элементов в отсортированном порядке
//     cout << "Отсортированные элементы с балансом: ";
//     inOrder(root);
//     cout << endl;
//     return 0;
// }

// //2
// #include <iostream>
// using namespace std;
// // Структура узла АВЛ-дерева
// struct Node {
//     int key;        // Значение узла
//     Node* left;     // Левый потомок
//     Node* right;    // Правый потомок
//     int height;     // Высота узла
//     int balance;    // Баланс узла
// };

// // Функция создания нового узла
// Node* createNode(int key) {
//     Node* node = new Node;
//     node->key = key;
//     node->left = nullptr;
//     node->right = nullptr;
//     node->height = 1;
//     node->balance = 0;
//     return node;
// }

// // Функция расчета высоты дерева
// int getHeight(Node* node) {
//     return node ? node->height : 0;
// }

// // Функция обновления высоты узла
// void updateHeight(Node* node) {
//     if (node) {
//         node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
//         node->balance = getHeight(node->left) - getHeight(node->right);
//     }
// }

// // Функция вычисления баланса узла
// int getBalance(Node* node) {
//     return node ? node->balance : 0;
// }

// // Функция левого поворота
// Node* leftRotation(Node* node) {
//     Node* child = node->right;
//     node->right = child->left;
//     child->left = node;
//     updateHeight(node);
//     updateHeight(child);
//     return child;
// }

// // Функция правого поворота
// Node* rightRotation(Node* node) {
//     Node* child = node->left;
//     node->left = child->right;
//     child->right = node;
//     updateHeight(node);
//     updateHeight(child);
//     return child;
// }

// // Функция балансировки узла
// Node* balance(Node* node) {
//     updateHeight(node);
//     int balancef = getBalance(node);
//     // Левый перевес
//     if (balancef > 1) {
//         if (getBalance(node->left) < 0) {
//             node->left = leftRotation(node->left);
//         }
//         return rightRotation(node);
//     }
//     // Правый перевес
//     if (balancef < -1) {
//         if (getBalance(node->right) > 0) {
//             node->right = rightRotation(node->right);
//         }
//         return leftRotation(node);
//     }
//     return node; // Балансировка не требуется
// }

// // Функция вставки в АВЛ-дерево
// Node* insert(Node* root, int key) {
//     if (!root) return createNode(key);
//     if (key < root->key) {
//         root->left = insert(root->left, key);
//     } else if (key > root->key) {
//         root->right = insert(root->right, key);
//     } else {
//         return root; 
//     }
//     return balance(root);
// }

// // Функция симметричного (in-order) обхода 
// void inOrder(Node* root) {
//     if (root) {
//         inOrder(root->left);
//         cout << root->key << " (" << root->balance << ") ";
//         inOrder(root->right);
//     }
// }

// int main() {
//     Node* root = nullptr;
//     int keys[] = {200, 205, 15, 150,30, 20, 40, 10, 25, 50, 5, 35, 45, 55, 10, 100};
//     for (int key : keys) {
//         root = insert(root, key);
//     }
//     cout << "Отсортированные элементы с балансом: ";
//     inOrder(root);
//     cout << endl;
//     return 0;
// }


//3
// #include <iostream>
// using namespace std;

// // Структура узла красно-черного дерева
// struct Node {
//     int key;
//     Node* left;
//     Node* right;
//     Node* parent;
//     char color; 
//     Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr), color('R') {}
// };

// // Класс бинарного дерева поиска с проверкой свойств красно-черного дерева
// class BST {
// private:
//     Node* root;
//     //Вставка узла
//     Node* insertBST(Node* root, Node* newNode) {
//         if (!root) return newNode;
//         // Вставка в левое поддерево
//         if (newNode->key < root->key) {
//             root->left = insertBST(root->left, newNode);
//             root->left->parent = root;
//         // Вставка в правое поддерево    
//         } else {
//             root->right = insertBST(root->right, newNode);
//             root->right->parent = root;
//         }
//         return root;
//     }
//     // Симметричный (in-order) обход дерева
//     void inOrder(Node* node) {
//         if (node) {
//             inOrder(node->left);
//             cout << node->key << "(" << node->color << ") ";
//             inOrder(node->right);
//         }
//     }
//     // Проверка свойства 5: корень – черный.
//     bool check5() {
//         return root->color == 'B';
//     }
//     // Проверка свойства 3: если узел красный, то оба его сына – черные;
//     bool check3(Node* node) {
//         if (!node) return true;
//         // Если узел красный, проверяем цвета его потомков
//         if (node->color == 'R') {
//             if ((node->left && node->left->color == 'R') || 
//                 (node->right && node->right->color == 'R')) {
//                 return false;
//             }
//         }
//         return check3(node->left) && check3(node->right);
//     }

//     // Проверка свойства 4: . все пути, идущие от корня к любому фиктивному листу, содержат одинаковое количество черных узлов;
//     bool check4(Node* node, int blackCount, int& path) {
//         if (!node) { 
//             if (path == -1) { // Установка количества черных узлов на первом пути
//                 path = blackCount;
//             }
//             // Проверка, соответствует ли количество черных узлов на текущем пути общему количеству
//             return blackCount == path;
//         }
//         if (node->color == 'B') blackCount++;
//         return check4(node->left, blackCount, path) &&
//                check4(node->right, blackCount, path);
//     }

// public:
//     BST() : root(nullptr) {}
//     // Вставка нового ключа
//     void insert(int key) {
//         Node* newNode = new Node(key);
//         root = insertBST(root, newNode);
//         // Делаем корень черным
//         root->color = 'B';
//     }
//     // Вывод элементов в порядке возрастания
//     void print() {
//         inOrder(root);
//         cout << endl;
//     }
//     // Проверка свойств красно-черного дерева
//     void validate() {
//         bool f1 = check5();
//         bool f2= check3(root);
//         int path = -1;
//         bool f3 = check4(root, 0, path);

//         cout << "Проверка красно-черного дерева:\n";
//         cout << "1. Корень черный: " << (f1 ? "Да" : "Нет") << endl;
//         cout << "2. Нет двух красных подряд: " << (f2 ? "Да" : "Нет") << endl;
//         cout << "3. Одинаковая высота черных узлов: " << (f3 ? "Да" : "Нет") << endl;
//     }
// };

// int main() {
//     BST tree;
//     int keys[] = {10, 20, 30, 15, 25, 5, 1};
//     for (int key : keys) {
//         tree.insert(key);
//     }
//     cout << "Отсортированные элементы: ";
//     tree.print();
//     // Проверка свойств красно-черного дерева
//     tree.validate();

//     return 0;
// }
