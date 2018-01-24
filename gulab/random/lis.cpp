#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int bs(int *a,int n,int x){
	int l,r,m;
	l=0;
	r=n-1;
	int i=r;
	while(l<r){
		m=(l+r)/2;
		if(a[m]>=x){
			i=m;
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return i;
}

int lis(int *a,int n){
	int b[n],maxlen=0;
	b[0]=a[0];
	for (int i = 1; i < n; ++i)
	{
		if(a[i]>b[maxlen]){
			b[++maxlen]=a[i];
		}
		else
			b[bs(b,maxlen+1,a[i])]=a[i];
	}
	return maxlen+1;
}

int main(){
	int n;
	cin>>n;
	int *a=(int*)malloc((n)*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<lis(a,n)<<endl;
	int b[]={4,6};
	cout<<bs(b,2,5)<<endl;
}