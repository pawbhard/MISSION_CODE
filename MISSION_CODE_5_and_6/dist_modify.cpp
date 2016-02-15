#include<iostream>
#include<string.h>

#define  I 4
#define  D 3
#define  R 7

using namespace std;

int min(int a,int b)
{
        return (a<b ? a : b);
}

int matr(char an[], char bm[], int n, int m)
{
        int mat[m+1][n+1];
        int pro[m][n];
	// pro : no change =-1; insert =0; delete= 1; replace =2
	for(int i=0; i<=m;i++)
                for(int j=0;j<=n;j++)
                {
                        if(i==0)
                                {
					mat[i][j]=j*D;
					pro[i][j]=1;
								}	
                        else if(j==0)
                                { 
					mat[i][j]=i*I;
					pro[i][j]=0;
								}	
                        else
                                {
                                        if(an[j-1]==bm[i-1])
                                                { 
							mat[i][j]=mat[i-1][j-1];
							pro[i][j]=-1;
						}  	
                                        else
                                            {
						mat[i][j]=min(mat[i-1][j-1]+R,min(mat[i-1][j]+I,mat[i][j-1]+D));
						if(mat[i][j]==mat[i-1][j-1]+R)
							pro[i][j]=2;
						else if(mat[i][j]==mat[i-1][j]+I)
                                                    pro[i][j]=0;
						else
                                                    pro[i][j]=1;

					    }	
                                }
                }
        cout<<"\n";
        for(int l=0;l<=m;l++)
        {
                for(int d=0; d<=n;d++)
                        cout<<mat[l][d]<<" ";
                cout<<"\n";
        }

cout<<"\n Process \n ";
	for(int l=0;l<=m;l++)
        {
                for(int d=0; d<=n;d++)
                        cout<<pro[l][d]<<" ";
                cout<<"\n";
        }

int k=mat[m][n];
int ab[m+n];
int count=0;
int row=m;
int col=n;
int h=0;
while(k!=0)	//fastest way
//while(row!=0||col!=0)	//slowest way
{
	if(pro[row][col]==-1 || pro[row][col]==2)
	{	
		if(pro[row][col]==2)
			{ab[h]=2;
			count++;
			k-=R;
			h++;
			}
		row--;
		col--;
	}
	else if(pro[row][col]==0)
	{
		row--;
		k-=I;
		ab[h]=0;
		count++;
		h++;
	}
	else
	{
		col--;
		k-=D;
		ab[h]=1;
		h++;
		count++;
	}
}
cout<<"\n";
while(h!=0)
{
	if(ab[h-1]==1)
		cout<<"\tDeletion\t";
	else if(ab[h-1]==0)
		cout<<"\tInsertion\t";
	else if(ab[h-1]==2)
		cout<<"\tReplace\t";
	else
		cout<<"\tNochange\t";
	h--;
	count--;
}
//process(pro, m+1,n+1);
        return mat[m][n];
}

int main()
{
        char arrn[]={"coloor"};
        //{"abcdef"};
        char brrm[]={"colour"};
        //{"azced"};
        int n,m;
        n=strlen(arrn);
        m=strlen(brrm);
        int ans=matr(arrn,brrm,n,m);
        cout<<"\n ANSWER : "<<ans<<"\n";
        return 0;
}
           
