#include<iostream>

using namespace std;

int func_choco(int arr[], int n)
{
	int count=1,temp=0,i=0;
	while(!arr[i++])
	{
		if(i==n)
		{
			count=0;
			break;
		}
	}
	while(i<n)
	{
		if(!arr[i])
			temp++;
		else
		{
			count=count*(temp+1);
			temp=0;
		}
	i++;
	}
	return count;
}

int main()
{
	int n,p;
	int arr[100];
	//cout<<"\n Enter the number of pieces : ";
	cin>>n;
	//cout<<"\n Enter the 0 & 1 : ";
	for(int i=0;i<n;i++)
	 cin>>arr[i];
	p=func_choco(arr, n);
	cout<<"\n output : ";
	 cout<<p<<"\n";

	return 0;
}

