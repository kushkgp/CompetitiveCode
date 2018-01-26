#include <bits/stdc++.h>
using namespace std;

typedef struct lkasd{
	int sweetness;
	int quantity;
}sweet;

bool lessthan(sweet a,sweet b){
	return a.sweetness<b.sweetness;
}

int bs(sweet *a,int n,int x){ // just greater than bs
	int l,r,m;
	l=0;
	r=n-1;
	int i=r;
	while(l<r){
		m=(l+r)/2;
		if(a[m].sweetness>=x){
			i=m;
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return i;
}

int main(){
	int n,s,q,*b,m;
	int temp;
	sweet *a;
	cin>>n;
	temp = n;
	a = new sweet[n];
	b = new int[n];
	for (int i = 0; i < n; ++i)
		cin>>a[i].sweetness>>a[i].quantity;
	sort(a,a+n,lessthan);
	int max=INT_MIN,index;
	for (int i =n-1; i >=0; --i)
	{
		if(a[i].quantity>max)
			max = a[i].quantity;
		else
			a[i].quantity = max;
	}
	cin>>q;
	long long int r=0;
	while(q--){
		cin>>m;
		if(m<=a[n-1].sweetness){
			r+=a[bs(a,n,m)].quantity/m;
			// cout<<" asdf"<<bs(a,n,m)<<endl;
		}
	}
	cout<<r;
	if(r)
		cout<<"00";
	cout<<endl;
}