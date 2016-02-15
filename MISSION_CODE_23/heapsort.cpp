#include<iostream>

using namespace std;

struct heap
{
	int size;
	int *arr;
};

void swap(int *a, int *b)
{
	int t= *a;
	*a=*b;
	*b=t;
}

void heapify(heap* maxheap, int ind)
{
	int largest = ind;
	int left= 2*ind+1;
	int right = 2*ind+2;

	if(left < maxheap->size && maxheap->arr[left] > maxheap->arr[largest])
		largest = left;
	if(right < maxheap->size && maxheap->arr[right] >maxheap->arr[largest])
		largest = right;
	if (largest != ind)
	{
		swap(&maxheap->arr[largest] , &maxheap->arr[ind]);
		heapify(maxheap, largest);
	}
}

struct heap* create_maxheap(int *arr,int size)
{
	int i;
	heap* maxheap = new heap;
	maxheap->size = size;
	maxheap->arr=arr;

	for(i=(maxheap->size - 2) / 2; i >= 0; --i)
		heapify(maxheap,i);
	return maxheap;	
}

void sort(int *arr, int size)
{
	heap* maxheap = create_maxheap(arr, size);

	while(maxheap->size >1)
	{
		swap(&maxheap->arr[0], &maxheap->arr[maxheap->size -1]);
		--maxheap->size;

		heapify(maxheap, 0);
	}
}

void print(int* arr, int size)
{
	int i;
	for(i=0;i<size;i++)
		cout<<" "<<arr[i];
}

int main()
{
	int arr[]= {12, 11, 13, 5, 6, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"\n Given array is : ";
	print(arr,size);

	sort(arr,size);
	cout<<"\n Sorted array is \n";
	print(arr,size);
	return 0;
}
