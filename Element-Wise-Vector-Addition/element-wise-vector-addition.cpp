#include <iostream>
#include <vector> 
using namespace std;
void elementWiseAdd(const vector<int>& arr1, const vector<int>& arr2) 
{
    if (arr1.empty() || arr1.size() != arr2.size()) 
	{
        cout << "Error: Vectors must be non-empty and of equal size." << endl;
        return;
    }
    vector<int> arr3;
    for (int i = 0; i < arr1.size(); i++) 
	{
        arr3.push_back(arr1[i] + arr2[i]);
    }
    for (int i = 0; i < arr3.size(); i++) 
	{
        cout << arr3[i] << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};
   	elementWiseAdd(arr1, arr2);
    return 0;
}
