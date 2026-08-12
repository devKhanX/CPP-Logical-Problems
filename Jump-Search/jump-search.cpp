#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int jumpSearch(vector<int>& arr, int key);
int main()
{
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 57, 64};
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    int result = jumpSearch(arr, key);
    if(result != -1)
    {
        cout << "Value found at index " << result << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }
    return 0;
}

int jumpSearch(vector<int>& arr, int key)
{
    int n = arr.size();
    int jump = sqrt(n);
    int start = 0;
    int end = jump;
    while(end < n && arr[end - 1] < key)
    {
        start = end;
        end += jump;
    }
    for(int i = start; i < min(end, n); i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
