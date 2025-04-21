// //2
// #include <iostream>  
// using namespace std; 
// struct Node {
//     int data;  // Данные в узле
//     Node* next; // Указатель на следующий узел в списке
//     Node(int x) : data(x), next(nullptr) {} // Значение указателя next в nullptr
// };

// void splitList(Node* head, int x, Node*& lessHead, Node*& moreHead) {
//     lessHead = nullptr; // Создаем список с элементами меньше x 
//     moreHead = nullptr; // Создаем список с элементами больше или равно x 
//     Node* lessNode = nullptr; // Указатель на последний элемент списка с элементами меньше x
//     Node* moreNode = nullptr; // Указатель на последний элемент списка с элементами больше или равно x
//     while (head) { 
//         Node* nextNode = head->next; //  Указатель на следующий узел до изменения 
//         if (head->data < x) { //Для списка с элементами <х
//             if (lessHead == nullptr) { 
//                 lessHead = head;
//                 lessNode = head; 
//             } else { 
//                 lessNode->next = head; 
//                 lessNode = head; 
//             }
//             lessNode->next = nullptr; 
//         } else { // Для списка с элементами больше или равно x
//             if (moreHead == nullptr) { 
//                 moreHead = head; 
//                 moreNode = head; 
//             } else { 
//                 moreNode->next = head; 
//                 moreNode = head; 
//             }
//             moreNode->next = nullptr; 
//         }

//         head = nextNode; // Переходим к следующему узлу в исходном списке
//     }
// }

// // Функция для вывода элементов односвязного списка 
// void display(Node* node){
//     while (node != NULL){
//         cout << node->data <<" -> ";
//         node = node->next;
//     }
//     cout << "NULL" <<endl;
// }

// int main() {
//     Node* head = new Node(1);
//     head->next = new Node(2);
//     head->next->next = new Node(3);
//     head->next->next->next = new Node(4);
//     head->next->next->next->next = new Node(5);
//     head->next->next->next->next->next = new Node(6);
//     int x; 
//     cout << "X: "; 
//     cin >> x;
//     Node* lessHead = nullptr; // Указатель на голову списка с элементами меньше x
//     Node* moreHead = nullptr; // Указатель на голову списка с элементами больше или равно x
//     splitList(head, x, lessHead, moreHead); 
//     cout << "Меньше " << x << ": "; 
//     display(lessHead); 
//     cout << "Больше или равно " << x << ": "; 
//     display(moreHead); 
//     // Очистка памяти 
//     Node* current = lessHead; 
//     while (current) { 
//         Node* next = current->next; 
//         delete current; 
//         current = next; 
//     }
//     current = moreHead;
//     while (current) { 
//         Node* next = current->next; 
//         delete current; 
//         current = next; 
//     }

//     return 0; 
// }
 


//5
#include <iostream>  
using namespace std; 
struct Node {
    int data;  // Данные в узле
    Node* next; // Указатель на следующий узел в списке
    Node(int x) : data(x), next(nullptr) {} // Значение указателя next в nullptr
};

void splitList(Node* head, int x, Node*& lessHead, Node*& moreHead) {
    lessHead = nullptr; // Создаем список с элементами меньше x 
    moreHead = nullptr; // Создаем список с элементами больше или равно x 
    Node* lessNode = nullptr; // Указатель на последний элемент списка с элементами меньше x
    Node* moreNode = nullptr; // Указатель на последний элемент списка с элементами больше или равно x
    while (head) { 
        Node* nextNode = head->next; //  Указатель на следующий узел до изменения 
        if (head->data < x) { //Для списка с элементами <х
            if (lessHead == nullptr) { 
                lessHead = head;
                lessNode = head; 
            } else { 
                lessNode->next = head; 
                lessNode = head; 
            }
            lessNode->next = nullptr; 
        } else { // Для списка с элементами больше или равно x
            if (moreHead == nullptr) { 
                moreHead = head; 
                moreNode = head; 
            } else { 
                moreNode->next = head; 
                moreNode = head; 
            }
            moreNode->next = nullptr; 
        }

        head = nextNode; // Переходим к следующему узлу в исходном списке
    }
}

// Функция для вывода элементов односвязного списка 
void display(Node* node){
    while (node != NULL){
        cout << node->data <<" -> ";
        node = node->next;
    }
    cout << "NULL" <<endl;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(3);
    display(head);
    Node* head1 = new Node(5);
    head1->next = new Node(6);
    head1->next->next = new Node(4);
    display(head1);
    int x; 
    cout << "X: "; 
    cin >> x;
    Node* lessHead = nullptr; // Указатель на голову списка с элементами меньше x
    Node* moreHead = nullptr; // Указатель на голову списка с элементами больше или равно x
    splitList(head, x, lessHead, moreHead); 
    cout << "Меньше " << x << ": "; 
    display(lessHead); 
    cout << "Больше или равно " << x << ": "; 
    display(moreHead); 
    // Очистка памяти 
    Node* current = lessHead; 
    while (current) { 
        Node* next = current->next; 
        delete current; 
        current = next; 
    }
    current = moreHead;
    while (current) { 
        Node* next = current->next; 
        delete current; 
        current = next; 
    }

    return 0; 
}
 