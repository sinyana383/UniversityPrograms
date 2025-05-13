#include <iostream>
#include "MyQueue.h"
#include <cstdlib>
#include <ctime>      

class Numbers : public MyQueue
{
public:
    int Get(MyQueue& q, int index);
    void Set(MyQueue& q, int index, int newValue);
    void ShellSort(MyQueue& q);
    int GetSize(MyQueue& q);
};

int Numbers::Get(MyQueue& q, int index) {
                                            N_op += 1;
    if (index < 0) {                        
        std::cout << "Error" << std::endl;  N_op += 2;
                                            N_op += 1;
        return -1;
    }

    MyQueue temp = nullptr;     N_op += 1;
    int value = -1;             N_op += 1;
    int currentPos = 0;         N_op += 1;

                                    N_op += 3; // будет лишние +2, если зайти в цикл. Но зато будет 2, если проверяем, но не заходим
    while (!q.IsEmpty()) {          N_op += 3;
        int val = q.Pop();          N_op += 3;
                                    N_op += 1;
        if (currentPos == index) {
            value = val;            N_op += 1;
        }
        temp.Push(val);             N_op += 3;
        currentPos++;               N_op += 1;
    }
                                    N_op += 3;
    while (!temp.IsEmpty()) {       N_op += 3;
        q.Push(temp.Pop());         N_op += 4;
    }
                                    N_op += 1;
    if (index >= currentPos) {
                                    N_op += 6;
        std::cout << "Error: " << index << " >= queue size (" << currentPos << ")" << std::endl;
                                    N_op += 1;
        return -1;
    }
                                    N_op += 1;
    return value;
}

int Numbers::GetSize(MyQueue& q) {  N_op += 1;
    MyQueue temp = nullptr;         N_op += 1;
    int size = 0;                   N_op += 1;
                                    N_op += 3;
    while (!q.IsEmpty()) {          N_op += 3;
        temp.Push(q.Pop());         N_op += 4;
        ++size;                     N_op += 1;
    }
                                    N_op += 3;
    while (!temp.IsEmpty()) {       N_op += 3;
        q.Push(temp.Pop());         N_op += 4;
    }
                                    N_op += 1;
    return size;
}

void Numbers::Set(MyQueue& q, int index, int newValue) {    N_op += 3;
                                            N_op += 1;
    if (index < 0) {
        std::cout << "Error" << std::endl;  N_op += 2;
                                            N_op += 1;
        return;
    }

    MyQueue temp = nullptr;                 N_op += 1;
    int currentPos = 0;                     N_op += 1;
    bool indexFound = false;                N_op += 1;

    while (!q.IsEmpty()) {                  N_op += 3;
        int val = q.Pop();                  N_op += 3;
        if (currentPos == index) {
            val = newValue;
            indexFound = true;
        }
        temp.Push(val);
        currentPos++;
    }

    while (!temp.IsEmpty()) {
        q.Push(temp.Pop());
    }

    if (!indexFound) {
        std::cout << "Error: " << index << " >= queue size (" << currentPos << ")" << std::endl;
    }
}

void Numbers::ShellSort(MyQueue& q) {
    int n = GetSize(q);

    if (n <= 1) {
        std::cout << "1 element" << std::endl;
        return;
    }

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = Get(q, i);
            if (temp == -1) {
                std::cout << "error" << i << std::endl;
                return;
            }

            int j;
            for (j = i; j >= gap; j -= gap) {
                int gapVal = Get(q, j - gap);
                if (gapVal == -1) {
                    std::cout << "error" << (j - gap) << std::endl;
                    return;
                }
                if (gapVal <= temp) break;
                Set(q, j, gapVal);
            }
            Set(q, j, temp);
        }
    }
}

int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int i, t_s, t_f;
    int Key[1000];
    int N = 100;
    Numbers list;

    for (i = 0; i < 1000; i++) {
        Key[i] = rand() % 999;
    }

    for (i = 0; i < 10; i++) {
        while (!list.IsEmpty()) {
            list.Pop();
        }

        for (int j = 0; j < N; j++) {
            list.Push(Key[j]);
        }

        list.N_op = 0;
        t_s = GetTickCount();
        list.ShellSort(list);
        t_f = GetTickCount();

        std::cout << "Номер сортировки: " << i + 1
            << " Количество отсортированных элементов: " << N
            << " Время сортировки: " << t_f - t_s << " Кол-во операций: " << list.N_op << std::endl;

        N += 100;

    }
/////////////////////////////////////////////////////////////
    /*
        int arr[] = { 12, 34, 54, 2, 3 };
        int n = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Array before sorting: \n";
        printArray(arr, n);

        shellSort(arr, n);

        std::cout << "\nArray after sorting: \n";
        printArray(arr, n);


        Numbers nums;

        int testValues[] = { 12, 34, 54, 2, 3 };
        for (int val : testValues) {
            nums.Push(val);
        }

        std::cout << "\n\nQueue before sorting: ";
        nums.Display();

        nums.ShellSort(nums);
        std::cout << "After ShellSort: ";
        nums.Display();
        */
    //system("pause");
    }
