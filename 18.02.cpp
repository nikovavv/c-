//3
// #include <iostream>
// using namespace std;
// struct Node {
//     int data; //Данные узла
//     Node* next; //Указатель на следующий узел
//     Node* prev; //Указатель на предыдущий узел
//     Node(int data) : data(data), next(nullptr), prev(nullptr) {}
// };

// //Функция для добавления узла в конец двусвязного списка
// void append(Node**head_ref, int new_data) {
//     Node* new_node = new Node(new_data); //Создаем новый узел
//     Node* last = *head_ref; //Указатель на последний узел
//     new_node->data = new_data; //Заполняем данные нового узла
//     new_node->next = NULL; //Следующий узел будет NULL
//     if (*head_ref == NULL){ //если список пуст
//         *head_ref = new_node; 
//         new_node->next = new_node;  //закольцовываем двусвязный список
//         new_node->prev = new_node;
//         return;
//     }
//     while (last->next != *head_ref){ //Находим последний узел
//         last = last->next;
//     }
//     new_node->next = *head_ref; //вставляем новый узел в конец списка
//     new_node->prev = last;
//     last->next = new_node;
//     (*head_ref)->prev = new_node;

// }

// //Функция для отображения двусвязного списка
// void display(Node* head){
//     Node* current = head;    
//     if (head==NULL){
//         cout <<"Список пуст";
//         return;
//     }
//     cout << "Список: ";
//     do {
//         cout << current->data << " <-> ";  
//         current = current->next;        
//     } while (current != head); 

//     cout << "Начало" << endl;
// }

// //Функция для проверки является ли кольцевым
// bool iscirc(Node* head){
//     if (head==NULL){ //проверка вдруг пустой
//         return true;
//     }
//     Node* current = head->next;
//     while (current != NULL && current != head) {
//         current = current->next;  //связываем элементы
//     }
//     return (current==head);
// }

// //Функция для Удаление узла по значению
// void delet(Node** head_ref, int key){
//     Node* current = *head_ref;
//     Node* prev = NULL;
//     if (*head_ref == NULL){ //проверка вдруг лист пустой
//         cout << "Лист пуст" <<endl;
//         return;
//     }
//     // Ищем узел с заданным значением
//     while (current->data != key) {
//         if (current->next == *head_ref) { // Если дошли до начала списка и не нашли элемент
//             cout << "Элемент " << key << " не найден в списке." << endl;
//             return; 
//         }
//         prev = current; // Запоминаем предыдущий узел
//         current = current->next; // Переходим к следующему узлу
//     }
//     if (current->next == *head_ref && prev == NULL) { // Если удаляем единственный узел в списке
//         delete current;  // Удаляем этот элементр
//         *head_ref = NULL; // Список становится пустым
//         return;
//     }
//     if (current == *head_ref) { // Если удаляем голову списка
//         Node* last = *head_ref; // Находим последний узел
//         while (last->next != *head_ref) {
//             last = last->next;
//         }
//         *head_ref = current->next; 
//         last->next = *head_ref; // последний элемент начинает указывать на новую голову
//         (*head_ref)->prev = last;  // У новой головы указатель на предыдущий узел
//         delete current; 
//     } else { // Удаляем узел в середине или в конце списка
//         prev->next = current->next; // Предыдущий узел теперь указывает на следующий после удаляемого
//         (current->next)->prev = prev; // У следующего после удаляемого узла меняем указатель на предыдущий элемент
//         delete current; // Освобождаем память, занимаемую удаляемым узлом
//     }
// }
// int main() {
//     Node* head = NULL;
//     append(&head,1);
//     append(&head,2);
//     append(&head,3);
//     display(head);
//     cout << "Это кольцо?";
//     if (iscirc(head)) {  
//         cout << " Да" << endl;   
//     } else {
//         cout << " Нет" << endl; 
//     }
//     delet(&head, 2); 
//     cout << "Элемент 2 удален. ";
//     display(head); 
//     delet(&head, 1); 
//     cout << "Элемент 1 удален. ";
//     display(head);
//     delet(&head, 3); 
//     cout << "Элемент 3 удален. ";
//     display(head);
//     return 0;
// }


// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     Node* next; //Указатель на следующий узел 
//     Node* prev; //Указатель на предыдущий узел
// };
// bool proskok(Node* head) {
//     Node* current = head;
//     while (current != NULL) {
//         if (current->next != NULL && current->next->prev != current) { //Проверка есть ли проскок
//             return true; 
//         }
//         current = current->next;
//     }
//     return false; //Если проскоков нет
// }
// int main() {
//     Node* head1 = new Node{1, nullptr, nullptr};
//     Node* node2 = new Node{2, nullptr, head1};
//     Node* node3 = new Node{3, nullptr, node2};
//     head1->next = node2;
//     node2->next = node3;
//     cout << "Количество проскоков: " << proskok(head1) << endl; 
//     Node* head2 = new Node{1, nullptr, nullptr};
//     Node* node2a = new Node{2, nullptr, head2};
//     Node* node3a = new Node{3, nullptr, node2a};
//     head2->next = node2a;
//     node2a->next = node3a;
//     node3a->prev = head2; 
//     cout << "Количество проскоков: " << proskok(head2) << endl;
//     return 0;
// }


//4
#include <iostream>
using namespace std;
struct Node {
    int data; //Данные узла
    Node* next; //Указатель на следующий узел
    Node* prev; //Указатель на предыдущий узел
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

//Функция для добавления узла в конец двусвязного списка
void append(Node**head_ref, int new_data) {
    Node* new_node = new Node(new_data); //Создаем новый узел
    Node* last = *head_ref; //Указатель на последний узел
    new_node->data = new_data; //Заполняем данные нового узла
    new_node->next = NULL; //Следующий узел будет NULL
    if (*head_ref == NULL){ //если список пуст
        *head_ref = new_node; 
        new_node->next = new_node;  //закольцовываем двусвязный список
        new_node->prev = new_node;
        return;
    }
    while (last->next != *head_ref){ //Находим последний узел
        last = last->next;
    }
    new_node->next = *head_ref; //вставляем новый узел в конец списка
    new_node->prev = last;
    last->next = new_node;
    (*head_ref)->prev = new_node;

}

//Функция для отображения двусвязного списка
void display(Node* head){
    Node* current = head;    
    if (head==NULL){
        cout <<"Список пуст";
        return;
    }
    cout << "Список: ";
    do {
        cout << current->data << " <-> ";  
        current = current->next;        
    } while (current != head); 

    cout << "Начало" << endl;
}

//Функция для проверки является ли кольцевым
bool iscirc(Node* head){
    if (head==NULL){ //проверка вдруг пустой
        return true;
    }
    Node* current = head->next;
    while (current != NULL && current != head) {
        current = current->next;  //связываем элементы
    }
    return (current==head);
}

//Функция для Удаление узла по значению
void delet(Node** head_ref, int key){
    Node* current = *head_ref;
    Node* prev = NULL;
    if (*head_ref == NULL){ //проверка вдруг лист пустой
        cout << "Лист пуст" <<endl;
        return;
    }
    // Ищем узел с заданным значением
    while (current->data != key) {
        if (current->next == *head_ref) { // Если дошли до начала списка и не нашли элемент
            cout << "Элемент " << key << " не найден в списке." << endl;
            return; 
        }
        prev = current; // Запоминаем предыдущий узел
        current = current->next; // Переходим к следующему узлу
    }
    if (current->next == *head_ref && prev == NULL) { // Если удаляем единственный узел в списке
        delete current;  // Удаляем этот элементр
        *head_ref = NULL; // Список становится пустым
        return;
    }
    if (current == *head_ref) { // Если удаляем голову списка
        Node* last = *head_ref; // Находим последний узел
        while (last->next != *head_ref) {
            last = last->next;
        }
        *head_ref = current->next; 
        last->next = *head_ref; // последний элемент начинает указывать на новую голову
        (*head_ref)->prev = last;  // У новой головы указатель на предыдущий узел
        delete current; 
    } else { // Удаляем узел в середине или в конце списка
        prev->next = current->next; // Предыдущий узел теперь указывает на следующий после удаляемого
        (current->next)->prev = prev; // У следующего после удаляемого узла меняем указатель на предыдущий элемент
        delete current; // Освобождаем память, занимаемую удаляемым узлом
    }
}
int main() {
    Node* head = NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    display(head);
    cout << "Это кольцо?";
    if (iscirc(head)) {  
        cout << " Да" << endl;   
    } else {
        cout << " Нет" << endl; 
    }
    delet(&head, 2); 
    cout << "Элемент 2 удален. ";
    display(head); 
    delet(&head, 1); 
    cout << "Элемент 1 удален. ";
    display(head);
    delet(&head, 3); 
    cout << "Элемент 3 удален. ";
    display(head);
    return 0;
}
