#include<iostream>
using namespace std;
int count(int num)
{
    int count = 0;
    while(num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int rev(int num, int count)
{
    int rev = 0, rem;

    while(num > 0)
    {
        rem = num % 10;

        if(count % 2 != 0)
        {
            rev = rev * 10 + rem;
        }
        num /= 10;      
        count--;
    }
    return rev;
}

int main()
{
    int num, numCount;
    cout << "Enter number: ";
    cin >> num;
    numCount = count(num);
    cout << "Reversed number is " << rev(num, numCount);
    return 0;
}
