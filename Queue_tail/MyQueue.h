#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue {
private:
    struct node {
        int value;
        node* next;
    };
    node* head, * tail;
public:
    unsigned long long int N_op = 0;
    MyQueue();
    ~MyQueue();
    void Push(int value);
    int Pop();
    void Display();
    bool IsEmpty();
};

#endif // MYQUEUE_H
