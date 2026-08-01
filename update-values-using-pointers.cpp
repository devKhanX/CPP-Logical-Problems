#include<iostream>
using namespace std;
#include<math.h>
void update(int *a,int *b)
{
    int old_a=*a;
    int old_b=*b;
    *a=old_a+old_b;
    *b=abs(old_a-old_b);
}
int main()
{
    int a,b;
    int *pa=&a,*pb=&b;
    cin>>a;
    cin>>b;
    update(pa,pb);
    cout<<a<<endl<<b;
    return 0;
}
