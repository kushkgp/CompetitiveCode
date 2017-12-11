#include <bits/stdc++.h>
#define size1 100000
#define size2 1000000000
using namespace std;
typedef vector<int> vi;
int n,c;

bool func(const vi & x, int k){
	int prevj=0,j=1;
	for (int i = 1; i < c; ++i)
	{
		if(j>=n) return false;
		if(x[j]-x[prevj]<k)
			i--;
		else
			prevj = j;
		j++;
	}
	// cout<<j<<" "<<c<<endl;
	return true;
}

int ans_bs(const vi & v){
	int x=0;
	int mid,l=0,r=v[n-1]+1;
	while(l<=r){
		mid=(l+r)/2;
		if(func(v,mid)){
			x=mid;
			l=mid+1;
			// cout<<"hello"<<endl;
		}
		else
			r=mid-1;
	}
	return x;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>c;
		vi v;
		v.resize(n,0);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		sort(v.begin(),v.end());
		cout<<ans_bs(v)<<endl;
	}
}