#include<iostream>
using namespace std;
int main()
{
	int arr[] = {2,3,5,4,5,3,4,7};	
	int n=sizeof(arr)/sizeof(arr[0]);
	int max=arr[0];
	int maxCount=0;
	for (int i=0;i<n;i++)
	{
	int count=0;
	for (int j=0;j<n;j++)
	{
		if (arr[i]==arr[j])
		{
			count++;
		}
	}
	if (count>maxCount)
	{
		maxCount=count;
		max=arr[i];
	}
}
	cout<<"The number with maximum occurance is "<<max;
}
