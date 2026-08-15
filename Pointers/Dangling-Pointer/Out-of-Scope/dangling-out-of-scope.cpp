//Returning the Address of a Local Variable from a function.
#include<iostream>
using namespace std;
int* getPointer()
{
	int value=10;
	return &value;
}
int main()
{
	int *ptr=getPointer();
	cout<<*ptr;
  	return 0;
}
/*Output
Undefined Behavior
Explanation: The local variable is destroyed when the function returns,
leaving the returned pointer dangling.*/
