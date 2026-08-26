#include<iostream>
using namespace std;
int printing(int nR)
{
	for (int i=nR;i>=1;i--)
	{
		for(char ch='A';ch<='A'+(i-1);ch++)
		{
			cout<<ch;
		}
		cout<<endl;
	}
}
int main()
{
		int nR;
		cout<<"Enter number of rows "<<endl;
		cin>>nR;
		printing(nR);
}
