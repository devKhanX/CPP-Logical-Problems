#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n, number, loc;
    n = sizeof(arr) / sizeof(arr[0]);
    loc = -1;
    cout << "Enter number to find: ";
    cin >> number;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == number)
        {
            loc = i;
            break;
        }
    }
    if (loc == -1)
        cout << "Value not found in the array";
    else
        cout << "Value found at index " << loc;
    return 0;
}
