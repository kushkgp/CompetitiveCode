#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005][3];
vector <pair <int, int> > vec;

bool comp( pair <int,int> A, pair <int, int> B )
{
	return A.first < B.first;
}

int recur( int fuel, int loc, int index )
{
	if( index == 0 && fuel >= loc )
		return 0;
	else
		if( index == 0 )
			return 1;

	if( loc - vec[index-1].first > fuel )
		return INT_MAX;
	else
		return  min( 1 + recur( fuel + vec[index-1].second - (loc - vec[index-1].first), vec[index-1].first, index - 1),
			recur( fuel, loc, index - 1 ));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int t1, t2, n, L, P;
		cin>>n;
		vec.clear();
		for( int i = 0; i < n; i++ )
		{
			cin>>t1>>t2;
			vec.push_back(make_pair(t1,t2));
		}

		sort(vec.begin(), vec.end(), comp);

		cin>>L>>P;

		memset(dp, -1, sizeof(dp));

		int ans = recur(P, L, n );

		if( ans >= INT_MAX )
			cout<<"-1"<<endl;
		else 
			cout<<ans<<endl;
	}
}