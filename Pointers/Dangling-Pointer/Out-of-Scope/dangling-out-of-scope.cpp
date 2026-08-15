//Variable Going Out of Scope
#include<iostream>
using namespace std;
int main()
{
	int *ptr;
	{
		int value=500;
		ptr=&value;
	}
	cout<<*ptr;
	return 0;
}
/*Output
Undefined Behavior
Explanation: Although the program may print 100 on some systems, 
the variable has already gone out of scope. Accessing it 
is undefined behavior, so the output is not guaranteed.*/
