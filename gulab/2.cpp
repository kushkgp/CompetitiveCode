#include <bits/stdc++.h>
using namespace std;

class event{
public:
	int s,e;
};

int bs(std::vector<event> & v,int n,int key){
	int x=-1;
	int mid,l=0,r=n-1;
	while(l<=r){
		mid=(l+r)/2;
		if(v[mid].e<=key){
			x=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return x;
}

class lessthan
{
public:
	bool operator()(event x,event y){
		return x.e<y.e;
	}
	
};

int ans(event *a,int n){
	std::vector<event> v(a,a+n);
	sort(v.begin(),v.end(),lessthan());
	int dp[n];
	dp[0]=1;
	for (int i = 1; i < n; ++i)
	{
		int x = bs(v,i,v[i].s);

		if(x!=-1){
			dp[i]=(1+dp[x]+dp[i-1])%100000000;
		}
		else dp[i]=(1+dp[i-1])%100000000;
	}
	return dp[n-1];
}

int main(){
	int n;
	event *a;
	cin>>n;
	while(n!=-1){
		a=new event[n];
		for (int i = 0; i < n; ++i){
			cin>>a[i].s>>a[i].e;
		}
		printf("%08d\n",ans(a,n));
		delete a;
		cin>>n;
	}
}