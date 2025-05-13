#include <iostream>
class MyQueue {
private:
    struct node {
        int value;
        node* next;
    };
    node* head, * tail;
public:
    MyQueue();
    ~MyQueue();
    void Push(int value);
    int Pop();
    void Display();
    bool IsEmpty();
};

