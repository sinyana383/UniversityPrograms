#include "MyQueue.h"

MyQueue::MyQueue() {
    head = tail = nullptr;   N_op += 2;
}
MyQueue::~MyQueue() {
    node* temp = nullptr;   N_op += 1;
    
    while (!IsEmpty()) {    N_op += 2;
        Pop();              N_op += 1;
    }
}
bool MyQueue::IsEmpty() {
                            N_op += 2;
    return head == nullptr;
}
int MyQueue::Pop() {
                                ++N_op;
    if (IsEmpty()) {
        std::cout << "No elements to pop" << std::endl; N_op += 2;
                                ++N_op;
        return -1;
    }

    node* temp = head;          ++N_op;
    int value = temp->value;    N_op += 2;

    head = head->next;          N_op += 2;
                                N_op += 1;
    if (head == nullptr) {
        tail = nullptr;         N_op += 1;
    }

    delete temp;                N_op += 1;
                                N_op += 1;
    return value;
}
void MyQueue::Push(int value) { N_op += 1;
    node* temp = new node;      N_op += 1;
    temp->value = value;        N_op += 2;
    temp->next = nullptr;       N_op += 2;

                                N_op += 1;
    if (IsEmpty()) {            
        head = tail = temp;     N_op += 2;
    }
    else {
        tail->next = temp;      N_op += 2;
        tail = temp;            N_op += 1;
    }
}
void MyQueue::Display() {
    node* temp = head;              N_op += 1;
    std::cout << "My Queue is: ";   N_op += 1;

    while (temp != nullptr) {               N_op += 1;
        std::cout << temp->value << " ";    N_op += 3;
        temp = temp->next;                  N_op += 2;
    }
    std::cout << std::endl;                 N_op += 1;
}
