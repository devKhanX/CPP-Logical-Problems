//Deallocating dynamically allocated memory using delete or free().
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int *ptr=(int*)malloc (20);
	free(ptr);	
	cout<<*ptr;
}
/*Output
Undefined Behavior
Explanation: The program accesses memory after it has been released. 
The result is undefined and may differ across executions*/
