#include<iostream>
using namespace std;
void printPattern(int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter size ";
    cin>>n;
    printPattern(n);
}
