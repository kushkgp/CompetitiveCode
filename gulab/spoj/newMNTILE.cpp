#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long double a=1,x,y;
		n++,m++;
		for(i=1;i<=n/2;i++)
			for(j=1;j<=m/2;j++)
				x=2*cosl(M_PIl*i/(n)),y=2*cosl(M_PIl*j/(m)),a*=(x*x+y*y);
		cout<<(((n-1)*(m-1))&1?0:(long long)round(a))<<endl;
	}
}