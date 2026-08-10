#include<iostream>
using namespace std;
int main()
{
	int arr[5]={33,22,66,77,88};
	int largest=arr[0];
	int secondlargest=arr[0];
	for (int i=1;i<5;i++)
	{
		if (arr[i]>largest)
		largest=arr[i];
	}
	cout<<largest<<endl;
	for (int i=1;i<5;i++)
	{
		if (arr[i]>secondlargest && largest>secondlargest)
		{
			secondlargest=arr[i];
		}
	}
	cout<<"Second largest is "<<secondlargest;
}
