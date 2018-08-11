#include<bits/stdc++.h>
using namespace std;

long long solve(int n)
{
	unsigned long long A[n+1],B[n+1];
	A[0] = 1;
	A[1] = 0;
	B[1] = 1;
	B[0] = 0;

	if(n<2)
		return A[n];
	for(int i=2;i<=n;i++)
	{
		A[i] = 2*B[i-1] + A[i-2];
		B[i] = A[i-1] + B[i-2];
	}
	return A[n];
}

int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{

		printf("%llu\n", solve(n));
		cin>>n;
	}
}