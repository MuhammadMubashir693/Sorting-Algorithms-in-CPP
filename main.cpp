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

int main()
{
    srand(time(nullptr));

    vector<int> arr(10);

    for (auto &elem : arr)
    {
        elem = rand() % 100 + 1;
    }

    cout << "Unsorted array: ";
    printarray(arr);
    cout << "Mergesort steps:\n";
    mergesort(arr);
    cout << "Sorted array: ";
    printarray(arr);
}