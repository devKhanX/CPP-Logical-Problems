#include<iostream>
using namespace std;
int main()
{
	int n=50;
	float f=49.56;
	char c='$';
	void *ptr;
	ptr=&n;
	cout<<*(static_cast<int*>(ptr))<<endl;
	ptr=&f;
	cout<<*(static_cast<int*>(ptr))<<endl;
	ptr=&c;
	cout<<*(static_cast<int*>(ptr))<<endl;
	return 0;
}
