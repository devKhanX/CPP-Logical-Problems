// WILD POINTER
#include<iostream>
using namespace std;
int main()
{
    int* p;
    /* Some unknown memory location is being corrupted.*/
    *p = 12;
}
