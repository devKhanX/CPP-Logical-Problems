#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 1, -2, -5, 2, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int output[n];
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (pos < n)
            {
                output[pos] = arr[i];
                pos += 2;
            }
        }
        else
        {
            if (neg < n)
            {
                output[neg] = arr[i];
                neg += 2;
            }
        }
    }
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}
