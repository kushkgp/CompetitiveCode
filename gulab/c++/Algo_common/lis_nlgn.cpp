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

// calculates lis
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

// calculates lis and add it to array in i
int lis_f(const vi &a, vi& lis, int n){
	int b[n],maxlen=0;
	b[0]=a[0];
	lis[0]=1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]>b[maxlen]){
			b[++maxlen]=a[i];
			lis[i] = maxlen+1;
		}
		else{
			int x = bs(b,maxlen+1,a[i]);
			b[x]=a[i];
			lis[i] = x+1;
		}
	}
	return maxlen+1;
}
