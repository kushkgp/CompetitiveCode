#include<bits/stdc++.h>
using namespace std;

int get_num_tiles(int n)
{
	int A[n+1],B[n+1],C[n+1];
	A[0] = 1;
	A[1] = B[1] = C[1] = 1;
	C[0] = 0;
	if(n<1)
		return A[n];
	for(int i=2;i<=n;i++)
	{
		A[i] = A[i-1] + A[i-2] + 2*B[i-1] + C[i-1];
		B[i] = A[i-1] + B[i-1];
		C[i] = A[i-1] + C[i-2];
	}
	return A[n];
}

int main()
{
	int t;
	scanf("%d",&t);
	int i=1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d\n",i,get_num_tiles(n) );
		i++;
	}
}