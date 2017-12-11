#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int maxbitonic(int *a,int n){
	int fdp[n+1],bdp[n+2];
	fdp[0]=bdp[n+1]=0;
	for (int i = 1; i < n+1; ++i)
	{
		fdp[i]=0;
		for (int k = 0; k < i; ++k)
		{
			if(a[i]>=a[k]){
				if(fdp[i]<1+fdp[k])
					fdp[i]=1+fdp[k]; 
			}
		}
	}
	for (int i = n; i > 0 ; --i)
	{
		bdp[i]=0;
		for (int k = i+1; k < n+2; ++k)
		{
			if(a[i]>=a[k]){
				if(bdp[i]<1+bdp[k])
					bdp[i]=1+bdp[k]; 
			}
		}
	}
	int max=0;
	for (int i = 1; i < n+1; ++i)
	{
		int x=fdp[i]+bdp[i]-1;
		if (x>max){
			cout<<i<<endl;
			max=x;
			}
	}
	return max;
}

int main(){
	int n,*a;
	cin>>n;
	a=(int*)malloc((n+1)*sizeof(int));
	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
	}
	cout<<"max:"<<maxbitonic(a,n)<<endl;
	return 0;
}