#include <bits/stdc++.h>
#define ff first
#define ss second
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int ans(const vpii & v){
	int x=0,y=0,sum=0;
	tr(v,it){
		if(it->ss)	sum+=it->ff*(x+1),++y;
		else sum+=it->ff*(y+1),++x;
		// cout<<sum<<endl;
	}
	return sum;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		vpii v;
		v.resize(m+n-2);
		for (int i = 0; i < m-1; ++i)
		{
			cin>>v[i].ff;
			v[i].ss = 0;
		}
		for (int i = m-1; i < m+n-2; ++i)
		{
			cin>>v[i].ff;
			v[i].ss = 1;
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		cout<<ans(v)<<endl;
	}
	return 0;
}