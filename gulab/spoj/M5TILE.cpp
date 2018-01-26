#include<bits/stdc++.h>
#define F(x,y)for(int x=1;x<=y;x++)
#define C(x,y)4*powl(cosl(x*M_PIl/y),2)
main(){F(n,17){long double a=1;F(i,n)F(j,3)a*=C(i,(2*n+1))+C(j,6);printf("%.LF\n",n<17?a:a+13);}}