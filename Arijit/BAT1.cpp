#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n, m, k;
		cin>>n>>m>>k;

		vector <int> batch;
		vector <vector<int> > cost, rating;

		vector <vector <int> > greedy;

		int temp;
		for( int i = 0; i < n; i++)
		{
			cin>>temp;
			batch.push_back(temp);
		}

		for( int i = 0; i < n; i++)
		{
			vector <int> new1;
			cost.push_back(new1);
			for( int j = 0; j < m; j++)
			{
				cin>>temp;
				cost[i].push_back(temp);
			}
		}

		for( int i = 0; i < n; i++)
		{
			vector <int> new1;
			rating.push_back(new1);
			for( int j = 0; j < m; j++)
			{
				cin>>temp;
				rating[i].push_back(temp);
			}
		}

		int dp[21][1005];
		memset( dp, 0, sizeof(dp));
		int mrating =0, left;

		for( int i = 1; i<=k; i++ )
		{
		 	mrating = 0;
			for( int j = 0; j < n; j++ )
			{
				left = i - batch[j];

				if( left <= 0 )
					continue;

				cout<<"i= "<<i<<" "<<left<<endl;
				for( int u = 0; u < m; u++ )
				{	
					vec.push_back()
				}

				visited[n] = false;
			}
			dp[i] = mrating;
			cout<<dp[i]<<" ";
		}

		cout<<dp[k]<<endl;
	}
}

