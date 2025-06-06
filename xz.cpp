#include <iostream> // Подключаем библиотеку для ввода/вывода данных
using namespace std;  // Используем стандартное пространство имен для удобства

// Определение структуры узла двусвязного кольцевого списка
struct Node {
    int data;  // Поле данных (целое число)
    Node* next; // Указатель на следующий узел в списке
    Node* prev; // Указатель на предыдущий узел в списке

    // Конструктор для создания нового узла
    Node(int data) : data(data), next(nullptr), prev(nullptr) {} // Инициализируем data, next и prev
};

// Функция для добавления нового узла в конец двусвязного кольцевого списка
void append(Node** head_ref, int new_data) {
    // head_ref: Указатель на указатель на голову списка (для возможности изменения головы)
    // new_data: Данные для добавления в новый узел

    Node* new_node = new Node(new_data);  // Создаем новый узел, выделяем память и инициализируем данные
    Node* last = *head_ref; // Указатель на текущий последний узел (изначально равен голове списка)

    // Если список пуст
    if (*head_ref == nullptr) {
        *head_ref = new_node; // Новый узел становится головой
        new_node->next = new_node;  // Закольцовываем: следующий указывает на себя
        new_node->prev = new_node;  // Предыдущий тоже указывает на себя (для списка из одного элемента)
        return; // Завершаем функцию, т.к. список состоит только из одного элемента
    }

    // Если список не пуст: находим последний узел
    while (last->next != *head_ref) { // Идем по списку, пока не дойдем до головы (признак конца)
        last = last->next; // Переходим к следующему узлу
    }

    // Вставляем новый узел в конец списка (между последним и головой)
    new_node->next = *head_ref; // Новый узел указывает на голову (замыкаем кольцо)
    new_node->prev = last;  // Новый узел указывает на предыдущий последний узел
    last->next = new_node;  // Предыдущий последний узел указывает на новый узел
    (*head_ref)->prev = new_node;  // Голова указывает на новый узел как на предыдущий
}

// Функция для удаления узла по значению из двусвязного кольцевого списка
void deleteNode(Node** head_ref, int key) {
    // head_ref: Указатель на указатель на голову списка (для возможности изменения головы)
    // key: Значение, которое нужно удалить

    Node* current = *head_ref; // Указатель на текущий узел
    Node* prev = nullptr; // Указатель на предыдущий узел

    // Если список пуст, ничего не делаем
    if (*head_ref == nullptr) {
        cout << "Список пуст, удаление невозможно." << endl;
        return;
    }

    // Ищем узел с заданным значением
    while (current->data != key) {
        // Если дошли до начала списка и не нашли элемент
        if (current->next == *head_ref) {
            cout << "Элемент " << key << " не найден в списке." << endl;
            return; // Выходим из функции
        }

        prev = current; // Запоминаем предыдущий узел
        current = current->next; // Переходим к следующему узлу
    }

    // Если удаляем единственный узел в списке
    if (current->next == *head_ref && prev == nullptr) {
        delete current;  // Освобождаем память
        *head_ref = nullptr; // Список становится пустым
        return;
    }

    // Если удаляем голову списка
    if (current == *head_ref) {
        // Находим последний узел
        Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        *head_ref = current->next; // Сдвигаем голову на следующий элемент
        last->next = *head_ref; // Последний элемент начинает указывать на новую голову
        (*head_ref)->prev = last;  // У новой головы правильно устанавливаем указатель на предыдущий узел (последний)
        delete current; // Удаляем старую голову
    } else { // Удаляем узел в середине или в конце списка
        prev->next = current->next; // Предыдущий узел теперь указывает на следующий после удаляемого
        (current->next)->prev = prev; // У следующего после удаляемого узла меняем указатель на предыдущий элемент
        delete current; // Освобождаем память, занимаемую удаляемым узлом
    }
}
// Функция для отображения двусвязного кольцевого списка
void display(Node* head) {
    // head: Указатель на голову списка

    // Если список пуст, выводим сообщение
    if (head == nullptr) {
        cout << "Список пуст." << endl;
        return;
    }

    Node* current = head; // Указатель на текущий узел, начинаем с головы
    cout << "Список: ";   // Выводим заголовок

    // Обходим список и выводим данные, пока не вернемся к голове
    do {
        cout << current->data << " <-> "; // Выводим данные текущего узла
        current = current->next; // Переходим к следующему узлу
    } while (current != head); // Останавливаемся, когда возвращаемся к голове

    cout << "Начало" << endl;  // Указываем, что достигли начала списка
}

// Функция для проверки, является ли список кольцевым
bool isCircular(Node* head) {
    // head: Указатель на голову списка

    // Пустой список считаем кольцевым
    if (head == nullptr) {
        return true;
    }

    Node* current = head->next; // Начинаем со второго элемента

    // Обходим список, пока не дойдем до конца или вернемся к голове
    while (current != nullptr && current != head) {
        current = current->next; // Переходим к следующему узлу
    }

    // Если вернулись к голове, список кольцевой, иначе нет
    return (current == head);
}

int main() {
    Node* head = nullptr; // Инициализируем пустой список

    // Добавляем элементы в список
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    // Выводим список на экран
    cout << "Двусвязный кольцевой список: " << endl;
    display(head); // Выводим содержимое списка

    // Проверяем, является ли список кольцевым
    cout << "Является ли список кольцевым? " << boolalpha << isCircular(head) << endl;

    // Удаляем элемент из списка
    deleteNode(&head, 2);
    cout << "Список после удаления элемента 2: " << endl;
    display(head);

    // Удаляем голову списка
    deleteNode(&head, 1);
    cout << "Список после удаления головы: " << endl;
    display(head);

    //Проверка удаления последнего элемента
    deleteNode(&head,3);
    cout << "Список после удаления последнего элемента 3: " << endl;
    display(head);

        deleteNode(&head,4);
    cout << "Список после удаления последнего элемента 4: " << endl;
    display(head);
        cout << "Является ли список кольцевым? " << boolalpha << isCircular(head) << endl;

    // Важно: освобождаем память, чтобы не было утечек
    // Этот код следует добавить, чтобы освободить выделенную память
    // (Пропущено для краткости, но необходимо в реальных программах)

    return 0; // Возвращаем 0, сигнализируя об успешном завершении программы
}
