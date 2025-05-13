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
    if (index < 0) {                        N_op += 4;
        std::cout << "Error" << std::endl;
        return -1;
    }

    MyQueue temp = nullptr;     N_op += 1;
    int value = -1;             N_op += 1;
    int currentPos = 0;         N_op += 1;

    while (!q.IsEmpty()) {
        int val = q.Pop();
        if (currentPos == index) {
            value = val;
        }
        temp.Push(val);
        currentPos++;
    }

    while (!temp.IsEmpty()) {
        q.Push(temp.Pop());
    }

    if (index >= currentPos) {
        std::cout << "Error: " << index << " >= queue size (" << currentPos << ")" << std::endl;
        return -1;
    }

    return value;
}

int Numbers::GetSize(MyQueue& q) {
    MyQueue temp;
    int size = 0;

    while (!q.IsEmpty()) {
        temp.Push(q.Pop());
        ++size;
    }

    while (!temp.IsEmpty()) {
        q.Push(temp.Pop());
    }

    return size;
}

void Numbers::Set(MyQueue& q, int index, int newValue) {
    if (index < 0) {
        std::cout << "Error" << std::endl;
        return;
    }

    MyQueue temp;
    int currentPos = 0;
    bool indexFound = false;

    while (!q.IsEmpty()) {
        int val = q.Pop();
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
