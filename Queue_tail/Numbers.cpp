#include "Numbers.h"

#include <iostream>
using namespace std;

int Numbers::Get(int index) {               N_op += 1;
                                            N_op += 1;
    if (index < 0) {
        cout << "Error" << endl;            N_op += 2;
                                            N_op += 1;
        return -1;
    }

    MyQueue temp;
    int value = -1;                 N_op += 1;
    int currentPos = 0;             N_op += 1;

                                    N_op += 3;
    while (!IsEmpty()) {            N_op += 2;
        int val = Pop();            N_op += 2;
                                    N_op += 1;
        if (currentPos == index) {
            value = val;            N_op += 1;
        }
        temp.Push(val);             N_op += 2;
        currentPos++;               N_op += 1;
    }
                                    N_op += 3;
    while (!temp.IsEmpty()) {       N_op += 3;
        Push(temp.Pop());           N_op += 3;
    }
                                    N_op += 1;
    if (index >= currentPos) {
                                    N_op += 6;
        cout << "Error: " << index << " >= queue size (" << currentPos << ")" << endl;
                                    N_op += 1;
        return -1;
    }
                                    N_op += 1;
    return value;
}

int Numbers::GetSize() {
    MyQueue temp;
    int size = 0;                   N_op += 1;
                                    N_op += 3;
    while (!IsEmpty()) {            N_op += 2;
        temp.Push(Pop());           N_op += 3;
        ++size;                     N_op += 1;
    }
                                    N_op += 3;
    while (!temp.IsEmpty()) {       N_op += 3;
        Push(temp.Pop());           N_op += 3;
    }
                                    N_op += 1;
    return size;
}

void Numbers::Set(int index, int newValue) {N_op += 2;
                                            N_op += 1;
    if (index < 0) {
        cout << "Error" << endl;            N_op += 2;
        return;
    }

    MyQueue temp;
    int currentPos = 0;                     N_op += 1;
    bool indexFound = false;                N_op += 1;

    while (!IsEmpty()) {                    N_op += 2;
        int val = Pop();                    N_op += 2;
        if (currentPos == index) {          N_op += 1;
            val = newValue;                 N_op += 1;
            indexFound = true;              N_op += 1;
        }
        temp.Push(val);                     N_op += 2;
        currentPos++;                       N_op += 1;
    }
                                            N_op += 3;
    while (!temp.IsEmpty()) {               N_op += 3;
        Push(temp.Pop());                   N_op += 3;
    }
                                            N_op += 1;
    if (!indexFound) {
                                            N_op += 6;
        cout << "Error: " << index << " >= queue size (" << currentPos << ")" << endl;
    }
}

void Numbers::ShellSort() {
    int n = GetSize();                          N_op += 2;
                                                N_op += 1;
    if (n <= 1) {
        cout << "1 element" << endl;            N_op += 2;
        return;
    }
                                                N_op += 2 + 1;
    for (int gap = n / 2; gap > 0; gap /= 2) {  N_op += 1 + 1;
                                                N_op += 1 + 1;
        for (int i = gap; i < n; i++) {         N_op += 1 + 1;
            int temp = Get(i);                  N_op += 3;
                                                N_op += 1;
            if (temp == -1) {
                cout << "error" << i << endl;   N_op += 3;
                return;
            }
            int j = 0;                              N_op += 1;
                                                    N_op += 1 + 1;
            for (j = i; j >= gap; j -= gap) {       N_op += 1 + 1;
                int gapVal = Get(j - gap);     N_op += 4;
                if (gapVal == -1) {                 N_op += 1;
                    cout << "error" << (j - gap) << endl;   N_op += 4;
                    return;
                }
                if (gapVal <= temp) break;          N_op += 1;
                Set(j, gapVal);       N_op += 2;
            }
            Set(j, temp);             N_op += 2;
        }
    }
}