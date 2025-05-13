#include "MyQueue.h"

MyQueue::MyQueue() {
    head = tail = nullptr; N_op += 2;
}
MyQueue::~MyQueue() {
    node* temp = nullptr;   N_op += 1;
    while (!IsEmpty()) {    N_op += 3;
        Pop();
    }
}
bool MyQueue::IsEmpty() {
    N_op += 2;
    return head == nullptr;
}
int MyQueue::Pop() {
    if (IsEmpty()) {        N_op += 4;
        std::cout << "No elements to pop" << std::endl;
        return -1;
    }

    node* temp = head;          N_op += 1;
    int value = temp->value;    N_op += 2;

    head = head->next;          N_op += 2;
    if (head == nullptr) {      N_op += 2;
        tail = nullptr;
    }

    delete temp;                N_op += 2;
    return value;
}
void MyQueue::Push(int value) {
    node* temp = new node;      N_op += 2;
    temp->value = value;        N_op += 2;
    temp->next = nullptr;       N_op += 2;

    if (IsEmpty()) {            N_op += 3;
        head = tail = temp;
    }
    else {                      N_op += 3;
        tail->next = temp;
        tail = temp;
    }
}
void MyQueue::Display() {
    node* temp = head;              N_op += 1;
    std::cout << "My Queue is: ";   N_op += 2;

    while (temp != nullptr) {               N_op += 1;
        std::cout << temp->value << " ";    N_op += 3;
        temp = temp->next;                  N_op += 2;
    }
    std::cout << std::endl;                 N_op += 1;
}
