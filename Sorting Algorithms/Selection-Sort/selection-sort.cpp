#include <iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&arr)
{
    int n=arr.size();
    for (int i=0;i<n;i++)
    {
        int smallestIdx=i;
        for (int j=i;j<n;j++)
        {
            if(arr[j]<arr[smallestIdx])
            {
                smallestIdx=j;
            }
        }
        swap(arr[i],arr[smallestIdx]);
    }
}
void printArray(vector<int>&arr)
{
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int> arr={4,1,5,2,3};
    selectionSort(arr);
    printArray(arr);
}
