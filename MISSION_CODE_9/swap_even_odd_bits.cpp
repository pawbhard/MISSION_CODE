#include<iostream>

using namespace std;

unsigned int swapBits(unsigned int n)
{
	unsigned int even_bits= n & 0XAAAAAAAA;//FOR 32 BITS
	unsigned int odd_bits= n & 0X55555555;
	
	even_bits >>= 1;// move right 
	odd_bits <<= 1;//move left
	
	return (even_bits | odd_bits);
}

int main()
{
	unsigned int x=23;//0001011
	cout<<"\n After swaping of 23 : "<<swapBits(x)<<" \n";
	//output :43 (00101011)

	return 0;
}
