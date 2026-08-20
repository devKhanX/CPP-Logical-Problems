#include <iostream> 
using namespace std; 
int sumProdDiff(int number)
{ 
    int sum = 0, pro = 1, digit = 0, result = 0; 
    while (number > 0) 
    { 
        digit = number % 10; 
        sum += digit; 
        pro *= digit; 
        number /= 10; 
    } 
    result=pro -sum; 
    return result; 
} 

int main()
{ 
    int number, result = 0; 
    cout<<"Enter a number: "; 
    cin>>number; 
    result=sumProdDiff(number); 
    cout<<"Sum and product difference is " << result << endl; 
    return 0; 
}
