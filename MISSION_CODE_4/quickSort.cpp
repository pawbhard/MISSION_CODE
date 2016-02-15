#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int t=*a;
	*a= *b;
	*b= t;
}

void printarr(int arr[], int size)
{
	for(int i=0; i < size;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";
}
int partition(int arr[], int beg, int last)
{
	int p = arr[last];
	int i = (beg - 1);

	for(int j=beg; j<last;j++)
	{
		if(arr[j] <= p)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[last]);
	return(i+1);
}

void QuickSort(int arr[], int beg, int last)
{
	if(beg < last)
	{
		int pp=partition(arr, beg, last);
		QuickSort(arr, beg, pp-1);
		QuickSort(arr, pp+1, last);
	}
}

int main()
{
	int arr[]={ 23, 18, 4 , 9, 98, 02, 10, 1, 7, 59, 40, 0, 11, 4, 44, 72};
	//int n=sizeof(arr)/sizeof(arr[0]);
	int n = 16;
	printarr(arr, n);
	QuickSort(arr, 0,n-1);
	cout<<"\n Sorted array is : ";
	printarr(arr, n);
	return 0;
}
