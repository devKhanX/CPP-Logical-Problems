##include<iostream>
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
	int num;
	bool ifPrime;
	int rev=0,rem=0;
	int ogNum;
	cout<<"Enter a number: ";
	cin>>num;
	ifPrime=isPrime(num);
	ogNum=num;
	if (ifPrime==true)
	{
		while(num>0)
		{
			rem=num%10;
			rev=rev*10+rem;
			num/=10;
		}
		ifPrime=isPrime(rev);
		if(ifPrime==true && rev!=ogNum)
		{	
			cout<<"Emirp Number";			
		}
		else
		{
			cout<<"Not an Emirp Number";
		}
	}
	else
	{
		cout<<"Not a Prime Number";
	}
}
