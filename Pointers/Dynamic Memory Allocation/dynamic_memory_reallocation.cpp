#include<iostream>
using namespace std;
int main()
{
	int *p=new int[5];
	p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;
	delete []p;
	p= new int[10];
	cout<<*p;
	return 0;
}
