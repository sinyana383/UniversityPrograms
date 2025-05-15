#include <iostream>
#include "MyQueue.h"
#include <windows.h>
#include <ctime>

using namespace std;



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
    srand(time(nullptr));

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
        list.ShellSort();
        t_f = GetTickCount();

        std::cout << "#" << i + 1
            << " Number of sorted elements: " << N
            << " Sort time: " << t_f - t_s
            << " Operation number (N_op): " << list.N_op << std::endl;

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
