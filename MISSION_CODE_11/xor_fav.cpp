#include<iostream>

using namespace std;

void display(int a, int b)
{
	cout<<"\t( "<<a+1<<", "<<b+1<<")";
}

int func(int arr[],int rr ,int ll,int k,int n ,int m)
{
	int i,j,prev,count=0;
	if(rr==ll && rr==k)
		{
			display(rr,rr);
			count++;
		}	
	for(i=rr-1;i<ll;i++)
	{
		prev=arr[i];
		if(arr[i]==k)
			{ 
				display(i,i);
				count++;
			}	
		for(j=i+1;j<ll;j++)
		{
			prev=prev^arr[j];
			if(prev==k)
				{
					display(i,j);
					count++;
				}	
		}
	}
	return (count);
}

int main()
{
	int n,m,arr[50],r[50],l[50],kk,count;
	//cout<<"\n Enter the size of array : ";
	cin>>n;
	//cout<<"\n Enter the total number  of query : ";
	cin>>m;
	//cout<<"\n Enter the elements of array \n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int j=0;j<m;j++)	
	{
	//	cout<<"\n Enter value or r & l of query "<<j+1<<" : ";
		cin>>r[j]>>l[j];
	}	
	int k;
	//cout<<"\n Enter your favourite number : ";
	cin>>k;
	for(kk=0;kk<m;kk++)
	{
		//cout<<"\n Solutions of query no. : "
	cout<<kk+1;//<<"\n";
		count=func(arr, r[kk], l[kk], k,n,m);
		//cout<<"\n Total number of solutions  : "
	cout<<count;
	}
	cout<<"\n";
	return 0;
}
