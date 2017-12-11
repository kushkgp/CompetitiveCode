#include <bits/stdc++.h>
using namespace std;

class event{
public:
	long s,e;
};

class lessthan
{
public:
	bool operator()(event x,event y){
		return x.e<y.e;
	}
	
}l;

int ans(event *a,int n){
	std::vector<event> v(a,a+n);
	sort(v.begin(),v.end(),l);
	int dp[n];
	// int s[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if(v[i].s>=v[j].e)
				dp[i]+=dp[j];
		}
	}
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=dp[i];
	}
	return sum;
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
		printf("%08d\n",ans(a,n)%100000000);
		// print(ans(a,n));
		// cout<<ans(a,n)<<endl;
		delete a;
		cin>>n;
	}
}