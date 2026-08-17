#include<iostream>
using namespace std;
bool isPrime (int n)
{
	if (n<=1)
	return false;
	if (n==2)
	return true;
	if (n%2==0)
	return false;
	for (int i=3;i<=n/i;i+=2)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int num,rev=0,rem=0,sum=0;
	cout<<"Enter number : "<<endl;
	cin>>num;
	while(num>0)
		{
			rem=num%10;
			rev=rev*10+rem;
			num/=10;
			sum+=rem;
		}
	if (isPrime(sum)==true)
	{
		cout<<"Prime Digit Sum Number";
	}
	else
	{
		cout<<"Not a Prime Digit Sum Number";
	}
}
