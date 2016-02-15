#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

bool isOneOnly(int n)
{
	if(n==0)
		return true;
	while(n)
	{
		if(n%10 != 1)
			return false;
		n/=10;	
	}
	return 1;
}

int main()
{
	int mul3[] = {0, 7, 4, 1, 8, 5, 2, 9, 6, 3};
	int num;
	cout<<"\n Enter a number ends with 3 : ";
	cin>>num;
	int carry=0;
	int mul_ans=0;
	int mul_by=7;
	while(1)
	{
		mul_ans= num*mul_by+carry;
		cout<<"1";
		carry=mul_ans/10;
		if(isOneOnly(carry))
			{
				cout<<carry;
				break;
			}
	mul_by = mul3[11-(carry % 10)];
	}
	return 0;
}
