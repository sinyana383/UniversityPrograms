//
// Created by sinya on 15.05.2025.
//

#ifndef NUMBERS_H
#define NUMBERS_H
#include "MyQueue.h"


class Numbers : public MyQueue
{
public:
    int Get(int index);
    void Set(int index, int newValue);
    void ShellSort();
    int GetSize();
};

#endif //NUMBERS_H
