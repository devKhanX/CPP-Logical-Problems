#include<iostream>
using namespace std;
void printPattern(int n)
{
    for (int i=5;i>=1;i--)
    {
        for (int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter size";
    cin>>n;
    printPattern(n);
}
