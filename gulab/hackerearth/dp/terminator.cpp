#include <bits/stdc++.h>
using namespace std;

typedef struct lskd
{
	int n1;
	int n2;
}intd;

bool myfunction(intd a,intd b){
	return a.n1<b.n1;
}

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
	// printf("asdf%d\n",b[0] );
	return maxlen+1;
}


int main(){
	int t,*b,n;
	intd *a;
	cin>>t;
	while(t--){
		cin>>n;
		a= new intd[n];
		b= new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i].n1>>a[i].n2;
		}
		sort(a,a+n,myfunction);
		for (int i = 0; i < n; ++i)
		{
			b[i]=a[i].n2;
			// printf(">%d\n", b[i]);
		}
		cout<<lis(b,n)<<endl;
		delete a;
		delete b;
	}
}