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

    bool is_empty() { //�������� �� ������� ������, ������� 1 ��� ������ � 0 ��� ��������
        return front == nullptr;
    }

    //1. ���������� �������� � �����
    void push_back(int value) { //��������� �������� � �����
        Node* p = new Node();
        if (is_empty()) { //���� �� ������, �� ������������� ���� �������� � ������� � �� �������
            front = p;
            back = p;
            return;
        }
        back->next = p; //������� ��������� ��������� �� � � � ���������� ���������
        back = p;
    }

    //2. ���������� �������� � ������
    void push_before(int value) { //��������� �������� � ������
        Node* p = new Node();
        if (is_empty()) { //���� �� ������, �� ������������� ���� �������� � ������� � �� �������
            front = p;
            back = p;
            return;
        }
        p->next = front; //���� �������� �� ������ ��
        front = p;
    }

    //3. ���������� � �������� �������
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

    //4. �������� �������� �� ��������
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

    //�������� ������� ��������
    void remove_first() {
        if (is_empty())
            return; //���� ������ - �����
        Node* curr = front; //��������� �� ������
        front = curr->next; //�������� ������� ����� ������ � ���������� ����
        delete curr; //������� ��� ������ ����
    }
    //�������� ����������
    void remove_last() {
        if (is_empty())
            return; //���� ������ - �����
        if (front == back) { //���� � ������ ���� ��������, �� �������� ������� �������� �������
            remove_first();
            return;
        }
        Node* curr = front; //��������� �� ������ ����
        while (curr->next != back)
            curr = curr->next; //���� �� ������ ���� ��������� ���� �� ����� ����������.
        curr->next = nullptr; //������� � ��������� ��������� ���� (������ ��������� �� �������
        delete back; // ������� ���������
        back = curr; //������ ��������� �� �������
    }

    //5. �������� �������� �� �����
    void delete_num(int index) {
        if (index == 0) { //���� ������ - �������� ������� ������
            remove_first();
            return;
        }
        if (index == size - 1) { //���� ��������� - �������� ������� ���������
            remove_last();
            return;
        }
        Node* curr = front;
        Node* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = curr; //���������� ���� �������
            curr = curr->next; //������� ���� ������
        }
        prev->next = curr->next;
        delete curr;//������� �������, ����� �� ������ ������� ��������
        size--;
    }

    //6. ����� �������� �� ��������
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
    //7. ����� �������� �� �������
    int find_pos(int index) {
        Node* curr = front; //��������� �� ������ ���� ������
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    //8. ������ ������
    void print() { //����� ������ �� �����
        if (is_empty()) return; //���� ��� �����
        Node* p = front; //��������� �� ������ ���� ������
        while (p) { //���� p �� ������ - ������� �������� � � ���� ������
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

};

//stack
class Stack {
public:
    Node* top;// ��������� �� ������� ������� �����
    Stack() {
        top = NULL;
    }
    List list;
    //������� ��� ������ � ������ �����
    int empty() {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    bool is_empty() { //�������� �� ������� 
        return top == nullptr;
    }

    // ����� ��� ���������� �������� � ����
    void push(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = top;
        top = newNode;
    }
    // ����� ��� �������� �������� �� �����
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
    
    int intop() { // ��������� �������� ������� �������� �������
        if (top != NULL) { // ���� ������� �����
            return top->value; // ������� ������������ ��������
        }
        return -1;
    }
};


class Func {
public:

    // ������� ��� ��������, �������� �� ������ ����������
    bool mathematical_oper(char symbol) { // ��� ������������ ������������
        return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
    }
    // ������� ��� ������ ������
    int error() {
        cout << "Error! Invalid expression!" << endl;
        return - 1;
    }
    // ������� ��� ������������ �������� ��� �������� �� ���������� � �����������
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
    void push(int value) { //����� ��� ���������� �������� � �������
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
    void pop() { //����� ��� �������� ������� �������� �������
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

    int peek() { // ��������� �������� ������� �������� �������
        if (front == NULL) { // ���� ������� �����
            return -1; 
        }
        return front->value;
    }

};

// ������� �������������� �� ���������� � �����������
class  FrominfixToPostfix {
public:
    Stack stack;
    Queue queue;
    Func function;
    string express(string exp) {
        for (int i = 0; i < exp.length(); i++) {// ���������� �� ���� ������
            char symbol = exp[i];
            if (symbol == ' ') {
                continue;
            }
            if (isdigit(symbol)) {// ���� ������ ���� �����, �� �� ���� � ����
                queue.push(symbol);
            } 
            else if (symbol == '(') {
                stack.push(symbol); //
            }
            else if (symbol == ')') {
                while (!stack.is_empty() && stack.intop() != '(') {//��� �� ������� �� ����� ��� ����� ����� ��������
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.pop(); // ������� ����������� ������ �� �����
            }
            else { // ���� ������� ������ - ��������
                while (!stack.is_empty() && function.priority(symbol) <= function.priority(stack.intop())) {
                    queue.push(stack.intop());
                    stack.pop();
                }
                stack.push(symbol);
            }
        }
        while (!stack.is_empty()) { // ������� ��������� �� �����, �������� �� � �������
            queue.push(stack.intop());
            stack.pop();
        }
        string postfix;
        while (!queue.isempty()) { // ������� ����������� ������
            postfix.push_back(queue.peek());
            queue.pop();
        }
        return postfix;
    }
};

// ������� ��� ���������� �������� ��������� �������� �������� �������
class SolutionPostfix {
public:
    Stack stack;
    Func function;
    int result(string expr) {
        int size = expr.length();
        int res;
        for (int i = 0; i < size; i++) { //���� ����������� �� ������
            char symbol = expr[i];
            if (symbol == ' ') {
                continue;
            }
            else if (isdigit(symbol)) { //�������� ������� �� i ������� � ������ �� �������� �� ��� ������
                int value = symbol - '0';
                stack.push(value);
            }
            else if (function.mathematical_oper(symbol)) { //�������������� ��������
                int num2 = stack.pop(); //��������� ������� ����� �� �����
                int num1 = stack.pop(); //��������� ��������� ����� �� �����
                if (symbol == '+') { //������ �� ���������� ������ � ������� � �������� �������������� ��������
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
                        cout << "Division by zero is not allowed!" << endl; //���� ����� �� 0 - �������� ������
                        return -1;
                    }
                    res = num1 / num2;
                    stack.push(res);
                }
            }
            else {
                function.error(); //���� ���� ������������ - ��������� ������
                return -1;
            }
        }
        if (stack.is_empty()) { //���� ����� ���, �� ������
            function.error();
            return -1;
        }
        int result = stack.pop(); //���� ������� ������� ����� � ����������� ��������� ���������� 
        if (!stack.is_empty()) { //���� � ����� ��� ���-�� ����, �� ������
            function.error();
            return -1;
        }
        return result; //���� ��� ������, �� �������� ���������, ���� ��� ���� - "-1"
    }
};

int main() {
    string str;
    SolutionPostfix solution;
    FrominfixToPostfix FromItoP;
    cout << "Enter the expression: ";
    getline(cin, str);
    if (str.length() < 3) { //��� ����� ��������� ������ 3 ��������� �������� ������, ��� ��� ������������ ���������
        cout << "Expression is not correct!" << endl;
    }
    else {
        string res = FromItoP.express(str);
        int res1 = solution.result(res);
        if (res1 != -1) { //�� Solution �������, �� ��� ������ ��������� ��� �� ������ � ������������ -1, ������� ����� �� ��������
            cout << "Expressiion result: " << res1 << endl;
        }
    }
}