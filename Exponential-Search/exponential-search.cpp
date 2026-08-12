#include <iostream>
#include <vector>
using namespace std;
void exponentialSearch(vector<int>& arr, int n, int key);
int binarySearch(vector<int>& arr, int start, int end, int key);

int main()
{
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 57, 64, 72};
    int key;
    int n = arr.size();
    cout << "Enter value to find in array: ";
    cin >> key;
    exponentialSearch(arr, n, key);
    return 0;
}

void exponentialSearch(vector<int>& arr, int n, int key)
{

    if (arr[0] == key)
    {
        cout << "Value found at index " << 0 << endl;
        return;
    }
    int i = 1;

    while (i < n && arr[i] <= key)
    {
        i = i * 2;
    }

    int find = binarySearch(arr, i / 2, min(i, n - 1), key);

    if (find != -1)
    {
        cout << "Value found at index " << find << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }
}

int binarySearch(vector<int>& arr, int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
