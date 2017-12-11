#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	long long int s,w;
	int p,q,r,w,x,y,z;
	cin>>n>>m;
	cin>>s>>p>>q>>r;
	cin>>w>>x>>y>>z;
	int *p = new int[m+1];
	for (int i = 2; i <= m; ++i)
	{
		for (int j = 2; j <= i; ++j)
		{
			if(i%j==0){
				p[i]=j;
				break;
			}
		}
	}
	int *pdp = new int[m+1];
	int *dp = new int[m+1];
	for (int i = 0; i < n; ++i)
	{
		
		for (int j = 1; j < m; ++j)
		{
			if(j==1){

			}
		}
	}




	delete p;
}