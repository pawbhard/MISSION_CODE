#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LPS(char *pat, int M, int *lps)
{
	int len=0;
	int i;
	lps[0]=0;
	i=1;
	while(i < M)
	{
		if (pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len !=0)
				len = lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp(char *pat,char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int *lps=(int *)malloc(sizeof(int)*M);

	LPS(pat, M, lps);

	int i=0,j=0;

	while(i<N)
	{
		if(pat[j] == txt[i])
		{
			i++;
			j++;
		}

		if(j == M)
		{
			printf("Found pattern at index %d \n", i-j);
			j=lps[j-1];
		}

		else if(i<N && pat[j]!=txt[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	free(lps);
}
int main()
{
	char *txt= "ABABDABACDABABCABAB";
	char *pat = "ABABCABAB";
	kmp(pat, txt);
	return 0;
}
