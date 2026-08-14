#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 0, -1, -2, 2, 0};
    int target = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << arr[i] << " "
                         << arr[j] << " "
                         << arr[k] << endl;
                }
            }
        }
    }
    return 0;
}
