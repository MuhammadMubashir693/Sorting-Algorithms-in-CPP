#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printarray(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }

    cout << "\n";
}

void bubblesort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr.at(j) > arr.at(j + 1))
            {
                cout << arr.at(j) << " and " << arr.at(j + 1) << " misplaced so swapping\n";
                swap(arr.at(j), arr.at(j + 1));
                swapped = true;
            }
        }

        cout << "After pass " << i + 1 << ": ";
        printarray(arr);

        if (!swapped)
        {
            return;
        }
    }
}

void selectionsort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        cout << "Initial min: " << arr.at(min) << "\n";

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr.at(min))
            {
                cout << "Found " << arr.at(j) << " as the new min\n";
                min = j;
            }
        }

        cout << "Swapping " << arr.at(min) << " and " << arr.at(i) << "\n";

        swap(arr.at(i), arr.at(min));

        cout << "After pass " << i + 1 << ": ";
        printarray(arr);
    }
}

void insertionsort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        cout << "Current element = " << key << " at position " << i << "\n";

        while (j >= 0 && arr[j] > key)
        {
            cout << "  Moving " << arr[j] << " from position " << j << " to position " << (j + 1) << "\n";
            arr[j + 1] = arr[j];
            j--;
        }

        if (j + 1 != i)
        {

            cout << "  Inserting " << key << " at position " << (j + 1) << "\n";
            arr[j + 1] = key;
        }
        else
        {
            cout << "  Element " << key << " already in correct position\n";
        }

        cout << "  After pass " << i << ": ";
        printarray(arr);
        cout << "\n";
    }
}

void merge(vector<int> &arr, vector<int> &left, vector<int> &right)
{
    int leftsize = left.size();
    int rightsize = right.size();

    cout << "  Merging left: ";
    printarray(left);
    cout << "  with right: ";
    printarray(right);

    int i = 0, j = 0, k = 0;

    while (i < leftsize && j < rightsize)
    {
        if (left.at(i) <= right.at(j))
        {
            cout << "    Taking " << left.at(i) << " from left\n";
            arr.at(k) = left.at(i);
            i++;
        }
        else
        {
            cout << "    Taking " << right.at(j) << " from right\n";
            arr.at(k) = right.at(j);
            j++;
        }
        k++;
    }

    while (i < leftsize)
    {
        cout << "    Copying remaining " << left.at(i) << " from left\n";
        arr.at(k) = left.at(i);
        i++;
        k++;
    }

    while (j < rightsize)
    {
        cout << "    Copying remaining " << right.at(j) << " from right\n";
        arr.at(k) = right.at(j);
        j++;
        k++;
    }

    cout << "  After merge: ";
    printarray(arr);
}

void mergesort(vector<int> &arr)
{
    int n = arr.size();

    if (n < 2)
    {
        return;
    }

    cout << "Splitting array: ";
    printarray(arr);

    int mid = n / 2;

    vector<int> left(mid);
    vector<int> right(n - mid);

    for (int i = 0; i < mid; i++)
    {
        left.at(i) = arr.at(i);
    }

    for (int j = mid; j < n; j++)
    {
        right.at(j - mid) = arr.at(j);
    }

    cout << " Left: ";
    printarray(left);
    cout << " Right: ";
    printarray(right);

    mergesort(left);
    mergesort(right);

    merge(arr, left, right);
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr.at(high);
    int i = low;

    cout << "Partitioning positions " << low << " to " << high
         << " with pivot " << pivot << "\n";

    for (int j = low; j < high; j++)
    {
        cout << "  Comparing " << arr.at(j) << " with pivot " << pivot << "\n";

        if (arr.at(j) <= pivot)
        {
            if (i != j)
            {
                cout << "  Swapping " << arr.at(i) << " and " << arr.at(j) << "\n";
                swap(arr.at(i), arr.at(j));
            }
            i++;
        }
    }

    if (i != high)
    {
        cout << "  Swapping pivot " << arr.at(high) << " with " << arr.at(i) << "\n";
        swap(arr.at(i), arr.at(high));
    }
    else
    {
        cout << "  Pivot is already in the correct position\n";
    }

    cout << "  After partition: ";
    printarray(arr);

    return i;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivotIndex = partition(arr, low, high);

    quicksort(arr, low, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, high);
}

void quicksort(vector<int> &arr)
{
    if (arr.size() > 1)
    {
        quicksort(arr, 0, arr.size() - 1);
    }
}

int main()
{
    srand(time(nullptr));

    int size = 0;
    while (size < 1)
    {
        cout << "Enter array size (positive): ";
        cin >> size;
    }

    vector<int> arr(size);

    cout << "Enter range for random numbers: ";
    int min;
    cin >> min;
    int max;
    cin >> max;

    for (auto &elem : arr)
    {
        elem = rand() % (max - min + 1) + min;
    }

    cout << "Unsorted array: ";
    printarray(arr);

    int choice = 0;
    while (choice < 1 || choice > 5)
    {
        cout << "Select a sorting algorithm:\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4. Merge Sort\n5. Quicksort\nEnter your choice: ";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        bubblesort(arr);
        break;

    case 2:
        selectionsort(arr);
        break;

    case 3:
        insertionsort(arr);
        break;

    case 4:
        mergesort(arr);
        break;

    case 5:
        quicksort(arr);
        break;

    default:
        break;
    }

    cout << "Sorted array: ";
    printarray(arr);
}