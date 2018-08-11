#include<bits/stdc++.h>
using namespace std;

#define vpi vector<pair<int,int> >
#define ff first
#define ss second

int main()
{
	int n;
	scanf("%d",&n);
	vpi v(n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&v[i].ff,&v[i].ss);
	vpi A(n+1),B(n+1);
	A[1].ff = v[0].ff;
	A[1].ss = v[0].ss;
	B[1].ff = v[0].ss;
	B[1].ss = v[0].ff;
	for(int i=2;i<=n;i++)
	{
		int h = v[i-1].ff;
		int w = v[i-1].ss;

		A[i].ff = A[i-1].ff + abs(A[i-1].ss - h) + w;
		A[i].ff = max(A[i].ff, B[i-1].ff + abs(B[i-1].ss - h) + w);
		A[i].ss = h;

		B[i].ff = B[i-1].ff + abs(B[i-1].ss - w) + h;
		B[i].ff = max(B[i].ff, A[i-1].ff + abs(A[i-1].ss - w) + h);
		B[i].ss = w;
	}
	printf("%d\n", max(A[n].ff,B[n].ff));
}