#include<iostream>

using namespace std;

long func(int a, int b)
{
//	cout<<"\n P \n";
	if (b==1)
		return a;
	else if(b&1)
		return (func(a<<1 , b>>1)+a);
	else
		return (func(a<<1, b>>1));
}

int main()
{
	int a=21,b=7;
	long c;
	if(a>b)
		c = func(a,b);
	else 
		c= func(b,a);
	cout<<"on multiplication of "<<a<<" & "<<b<<" : "<<c<<"\n";
	return 0;
}
