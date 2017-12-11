#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class bridge{
public:
	int a;
	int bindex;
};

class lessthan{
public:
	bool operator()(const bridge & a,const bridge & b){ return a.a<b.a;}

}myfunctor;

int maxbridge(bridge *b,int n){
	vector<bridge> v(b,b+n);
	int dp[n];
	sort(v.begin(),v.end(),myfunctor);

	for (int i = 0; i < n; ++i)
	{
		dp[i]=1;
		int max=0;
		for (int j = 0; j < i; ++j)
		{
			if(v[i].bindex>v[j].bindex)
				if (max<dp[j])
				{
					max=dp[j];
				}
		}
		dp[i]+=max;
	}
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		if (max<dp[i])
		{
			max=dp[i];
		}
	}
	return max;
}

int main(){
	int n;
	cin>>n;
	bridge *b;
	b=(bridge*)malloc(n*sizeof(bridge));
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i].a;
		b[i].bindex=i;
	}
	cout<<maxbridge(b,n)<<endl;
}