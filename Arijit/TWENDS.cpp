#include <bits/stdc++.h>

using namespace std;

long long int dp[1005][1005];

vector <int> vec;

long long int boob( vector <int> vec, int i, int j )
{
	if( i > j )
		return 0;

	if( dp[i][j]!= -1)
		return dp[i][j];

	long long int k,l;
	if( vec[j] > vec[i+1] )
		k = boob(vec,i+1,j-1);
	else
		k = boob(vec,i+2,j);

	if( vec[j-1] > vec[i] )
		l = boob(vec,i,j-2);
	else
		l = boob(vec,i+1,j-1);

	long long int ans = max( vec[i] + k, vec[j] + l);
	dp[i][j] = ans;
	return ans;
}

int main()
{
	int t = 0;
	while(1)
	{
		t++;
		int n, temp;
		cin>>n;

		if( n == 0 )
			return 0;

		vec.clear();
		long long int sum = 0;
		for( int i = 0; i < n; i++ )
		{
			cin>>temp;
			sum += temp;
			vec.push_back(temp);
		}
		memset(dp, -1, sizeof(dp));
		cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<boob(vec,0,n-1) - sum + boob(vec, 0, n-1 )<<" points."<<endl;
	}
}