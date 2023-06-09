#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

//list
class List {
public:
    Node* front;
    Node* back;
    int size;

    List() {
        front == NULL;
        back == NULL;
    }

    bool is_empty() { //проверка на пустоту списка, выводит 1 при пустом и 0 при обратном
        return front == nullptr;
    }

    //1. Добавления элемента в конец
    void push_back(int value) { //добавляем значения в конец
        Node* p = new Node();
        if (is_empty()) { //если он пустой, то присваивается одно значение к первому и ко второму
            front = p;
            back = p;
            return;
        }
        back->next = p; //двигаем последний указатель на р и р становится последним
        back = p;
    }

    //2. Добавления элемента в начало
    void push_before(int value) { //добавляем значение в начало
        Node* p = new Node();
        if (is_empty()) { //если он пустой, то присваивается одно значение к первому и ко второму
            front = p;
            back = p;
            return;
        }
        p->next = front; //сама написала не поняла че
        front = p;
    }

    //3. Добавление в заданную позицию
    void add_num(int value, int index) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (index == 1) {
            newNode->next = front;
            front = newNode;
            return;
        }
        Node* curr = front;
        for (int i = 1; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    //4. Удаление элемента по значению
    void delete_val(int value) {
        Node* temp = front;
        Node* prev = NULL;
        if (temp != NULL && temp->value == value) {
            front = temp->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->value != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) { return; }
        prev->next = temp->next;
        delete temp;
    }

    //удаление первого элемента
    void remove_first() {
        if (is_empty())
            return; //если пустое - выход
        Node* curr = front; //указатель на первый
        front = curr->next; //значение первого места уходит к следующему узлу
        delete curr; //удаляем тот первый узел
    }
    //удаление последнего
    void remove_last() {
        if (is_empty())
            return; //если пустое - выход
        if (front == back) { //если в списке одно значение, то вызываем функцию удаления первого
            remove_first();
            return;
        }
        Node* curr = front; //указатель на первый узел
        while (curr->next != back)
            curr = curr->next; //идем по списку пока следующий узел не равен последнему.
        curr->next = nullptr; //убираем у указателя следующий узел (делаем указатель на пустоту
        delete back; // удаляем последний
        back = curr; //меняем последний на текущий
    }

    //5. Удаление элемента по месту
    void delete_num(int index) {
        if (index == 0) { //если первый - вызываем удалить первый
            remove_first();
            return;
        }
        if (index == size - 1) { //если последний - вызываем удалить последний
            remove_last();
            return;
        }
        Node* curr = front;
        Node* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = curr; //пердыдущий стал текущим
            curr = curr->next; //текущий едет дальше
        }
        prev->next = curr->next;
        delete curr;//удаляем текущий, когда он достиг нужного значения
        size--;
    }

    //6. поиск элемента по значению
    int find_val(int value) {
        Node* curr = front;
        int index = 0;
        if (is_empty()) return -1;
        else {
            while (curr != nullptr) {
                if (curr->value == value) return index;
                curr = curr->next;
                index++;
            }
            return -1;
        }
    }
    //7. поиск элемента по позиции
    int find_pos(int index) {
        Node* curr = front; //указатель на первый узел списка
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    //8. Печать списка
    void print() { //вывод списка на экран
        if (is_empty()) return; //если там пусто
        Node* p = front; //указатель на первый узел списка
        while (p) { //пока p не пустой - выводим значение р и едем дальше
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

};

//stack
class Stack {
public:
    Node* top;// указатель на верхний элемент стека
    Stack() {
        top = NULL;
    }
    List list;
    //Функция для вывода о пустом стеке
    int empty() {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    bool is_empty() { //проверка на пустоту 
        return top == nullptr;
    }

    // Метод для добавления элемента в стек
    void push(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }
    // Метод для удаления элемента из стека
    int pop() {
        if (is_empty()) {
            empty();
        }
        int val = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    
    int intop() { // получение значения первого элемента очереди
        if (top != NULL) { // если очередь пуста
            return top->value; // вернуть некорректное значение
        }
        return -1;
    }
};


class Func {
public:

    // Функция для проверки, является ли символ оператором
    bool mathematical_oper(char symbol) { // Для постфиксного кальколятора
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
    }
    // Функция для вывода ошибки
    int error() {
        cout << "Error! Invalid expression!" << endl;
        return - 1;
    }
    // Функция для ранжирования символов для перевода из инфиксного в постфиксное
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
};

//queue
class Queue {
public:
    Node* front;
    Node* back;
    Queue() {
        front = NULL;
        back = NULL;
    }
    List list;
    void push(int value) { //Метод для добавления элемента в очередь
        Node* temp = new Node;
        temp->value = value;
        temp->next = NULL;
        if (front == NULL) {
            front = temp;
        }
        else {
            back->next = temp;
        }
        back = temp;
    }
    void pop() { //Метод для удаление первого элемента очереди
        Node* temp = new Node();
        if (front == NULL) {
            cout << "The queue is empty." << endl;
            return;
        }
        temp = front;
        front = front->next;
        delete temp;
    }

    bool isempty() {
        return (front == NULL);
    }

    int peek() { // получение значения первого элемента очереди
        if (front == NULL) { // если очередь пуста
            return -1; 
        }
        return front->value;
    }

};

// Функция преобразования из инфикстной в постфиксную
class  FrominfixToPostfix {
public:
    Stack stack;
    Queue queue;
    Func function;
    string express(string exp) {
        for (int i = 0; i < exp.length(); i++) {// Проходимся по всей строке
            char symbol = exp[i];
            if (symbol == ' ') {
                continue;
            }
            if (isdigit(symbol)) {// Если символ есть цифра, то он идет в стек
                queue.push(symbol);
            } 
            else if (symbol == '(') {
                stack.push(symbol); //
            }
            else if (symbol == ')') {
                while (!stack.is_empty() && stack.intop() != '(') {//Тут мы достаем из стека все числа между скобками
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.pop(); // Удаляем открывающую скобку из стека
            }
            else { // Если текущий символ - оператор
                while (!stack.is_empty() && function.priority(symbol) <= function.priority(stack.intop())) {
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.push(symbol);
            }
        }
        while (!stack.is_empty()) { // Удаляем операторы из стека, добавляя их в очередь
            queue.push(stack.intop());
            stack.pop();
        }
        string postfix;
        while (!queue.isempty()) { // Создаем постфиксную строку
            postfix.push_back(queue.peek());
            queue.pop();
        }
        return postfix;
    }
};

// Функция для вычисления значения выражения обратной польской нотации
class SolutionPostfix {
public:
    Stack stack;
    Func function;
    int result(string expr) {
        int size = expr.length();
        int res;
        for (int i = 0; i < size; i++) { //цикл прохождения по строке
            char symbol = expr[i];
            if (symbol == ' ') {
                continue;
            }
            else if (isdigit(symbol)) { //проверка символа на i позиции в строке на является ли оно числом
                int value = symbol - '0';
                stack.push(value);
            }
            else if (function.mathematical_oper(symbol)) { //математическая операция
                int num2 = stack.pop(); //извлекаем верхнее число из стека
                int num1 = stack.pop(); //извлекаем следубщее число из стека
                if (symbol == '+') { //дальше он сравнивает символ с текущим и проводит соответстующую операцию
                    res = num1 + num2;
                    stack.push(res);
                }
                else if (symbol == '-') {
                    res = num1 - num2;
                    stack.push(res);
                }
                else if (symbol == '*') {
                    res = num1 * num2;
                    stack.push(res);
                }
                else if (symbol == '/') {
                    if (num2 == 0) {
                        cout << "Division by zero is not allowed!" << endl; //если делим на 0 - выдается ошибка
                        return -1;
                    }
                    res = num1 / num2;
                    stack.push(res);
                }
            }
            else {
                function.error(); //если ввод некорректный - выводится ошибка
                return -1;
            }
        }
        if (stack.is_empty()) { //если ввода нет, то ошибка
            function.error();
            return -1;
        }
        int result = stack.pop(); //берём верхний элемент стека и присваиваем заначение результату 
        if (!stack.is_empty()) { //если в стеке еще что-то есть, то ошибка
            function.error();
            return -1;
        }
        return result; //если нет ошибок, то вернется результат, если они были - "-1"
    }
};

int main() {
    string str;
    SolutionPostfix solution;
    FrominfixToPostfix FromItoP;
    cout << "Enter the expression: ";
    getline(cin, str);
    if (str.length() < 3) { //при длине выражения меньше 3 элементов выдастся ошибка, так как недостаточно элементов
        cout << "Expression is not correct!" << endl;
    }
    else {
        string res = FromItoP.express(str);
        int res1 = solution.result(res);
        if (res1 != -1) { //тк Solution интовая, то при ошибке выводится соо об ошибке и возвращается -1, которое можно не выовдить
            cout << "Expressiion result: " << res1 << endl;
        }
    }
}