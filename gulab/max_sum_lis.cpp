#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

int maxincsum(int n,int *a){
	int s[n+1];
	s[0]=0;
	for (int i = 1; i < n+1; ++i)
	{
		s[i]=0;
		for (int k = 0; k < i; ++k)
		{
			int sum=0;
			if(a[k]<a[i])
				sum = s[k]+a[i];
			if(s[i]<sum)
				s[i]=sum;
		}
	}
	int maxsum=0;
	for (int i = 0; i < n+1; ++i)
	{
		if(maxsum<s[i])
			maxsum=s[i];
	}
	return maxsum;
}

int main(){
	int n;
	cin>>n;
	int *a;
	a=(int *)malloc((n+1)*sizeof(int));
	a[0]=0;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	cout<<maxincsum(n,a)<<endl;
	return 0;
}