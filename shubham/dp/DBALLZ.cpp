#include<bits/stdc++.h>
using namespace std;

#define degug(s) if(debug) cout<<s<<endl;
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef pair<int,int> pii;
typedef vector<pii> vpii;
// map<int,map<int,int> > m;
int debug = 0;

int gettyme(int E,int L,const vpii &v)
{
	int dp[L+1][E+1];
	// cout<<"here1"<<endl;
	for(int i=0;i<=L;++i)
		for(int j=0;j<=E;++j)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i-1][j];
			if(v[i-1].first <= j)
				dp[i][j] = max(dp[i][j],v[i-1].second + dp[i][j-v[i-1].first]);
		}
		// cout<<"here"<<endl;
	return dp[L][E];
}

int getmaxtime(int E,int L,int *arr,int *tym)
{
	map<int,map<int,int> > m;
	if(E == 0 || L == 0)
	{
		m[E][L] = 0;
		return 0;
	}
	if(m.find(E)!=m.end())
		{
			if(m[E].find(L)!= m[E].end())
				return m[E][L];
		}
		degug("here");
	int ans;
	if(m.find(E)!=m.end())
	{
		degug("here1");
		if(m[E].find(L-1)!=m[E].end())
		{
			degug("here3");
			ans = m[E][L-1];
		}
		else
			ans = getmaxtime(E,L-1,arr,tym);
	}
	else
	{
		degug("here2");
		ans = getmaxtime(E,L-1,arr,tym);
		// m[E][L-1] = ans;
	}
	if(arr[L-1] <= E)
	{
		if(m.find(E - arr[L-1])!=m.end())
		{
			if(m[E-arr[L-1]].find(L)!=m[E - arr[L-1]].end())
			{
				ans = max(ans,tym[L-1] + m[E-arr[L-1]][L]);
				return ans;
			}
		}
		int tmp = getmaxtime(E - arr[L-1],L,arr,tym);
		// m[E - arr[L-1]][L] = tmp;
		ans = max(ans,tym[L-1] + tmp);
	}
	m[E][L] = ans;
	return ans;
}

int main()
{
	BOOST;
	int t;
	// vector<vector<int> > dp(1000010,vector<int>(1005));
	cin>>t;
	while(t--)
	{
		int E,L;
		cin>>E>>L;
		vpii v;
		v.resize(L);
		for(int i=0;i<L;i++)
			cin>>v[i].first;
		for(int i=0;i<L;i++)
			cin>>v[i].second;
		cout<<gettyme(E,L,v)<<endl;
		// map<int,map<int,int> > :: iterator it;
		// for(it=m.begin();it!=m.end();it++)
		// {
		// 	map<int,int> :: iterator it1;
		// 	for(it1=(it->second).begin();it1!=(it->second).end();it1++)
		// 		cout<<"( "<<it->first<<" "<<it1->first<<" "<<it1->second<<" )";
		// 	cout<<endl;
		// }
		// m.clear();
	}
}