#include<bits/stdc++.h>
#define F(x,y)for(int x=1;x<=y;x++)
using namespace std;
int main()
{
	F(n,17)
	{
		long double a=1,x,y;
		F(i,n)F(j,3)x=2*cos(i*M_PIl/(n*2+1)),y=2*cos(j*M_PIl/6),a*=x*x+y*y;
		printf("%.LF\n",roundl(a));
	}
}