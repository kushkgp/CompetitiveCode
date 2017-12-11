#include <bits/stdc++.h>
#include <unordered_map>
#define mp make_pair
using namespace std;
typedef vector<int> vi;
typedef long long int ll;

ll ans(const vi & v, int n){
	unordered_map<int,int> m1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				ll x = (ll)(v[i])*v[j]+v[k];
				if(m1.find(x)!=m1.end())
					m1.insert(mp(x,0));
				m1[x]++;
			}
		}
	}
	ll retans=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if(!v[i])
					continue;
				int x = (ll)(v[i])*(v[j]+v[k]);
				if(m1.find(x)!=m1.end())
					retans+=m1[x];
			}
		}
	}
	return retans;
}

int main(){
	int n;
	cin>>n;
	vi v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&v[i]);
	cout<<ans(v,n)<<endl;
	return 0;
}