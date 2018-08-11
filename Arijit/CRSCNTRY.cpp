#include <bits/stdc++.h>

using namespace std;

long long int dp[2005][2005];

int LCS( vector <int> A, vector<int> B)
{
	for( int i = 0; i <= A.size(); i++ )
	{
		for( int j = 0; j <= B.size(); j++ )
		{
			if( i==0 || j==0 )
				dp[i][j]=0;
			else
				{
					if( A[i-1] == B[j-1] )
						dp[i][j] = 1 + dp[i-1][j-1];
					else 
						dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
				}
		}
	}

	return( dp[A.size()][B.size()]);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int temp;
		
		vector <int> arr;
		while(1)
		{
			cin>>temp;
			if( temp == 0 )
				break;

			arr.push_back(temp);
		}

		vector <vector<int> > vec;
		int i = 0;
		while(1)
		{
			vector <int> A;
			vec.push_back(A);
			while(1)
			{
				cin>>temp;		
				if( temp == 0 )
					break;
				vec[i].push_back(temp);
			}
			if( vec[i].size() < 2 )
				break;

			i++;
		}

		int ans = 0;

		for( int j = 0; j < i; j++ )
		{
			// cout<<i<<endl;
			memset(dp, -1, sizeof(dp));
			ans = max( ans, LCS(arr, vec[j]));
		}

		cout<<ans<<endl;
	}
}