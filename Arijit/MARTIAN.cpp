#include <bits/stdc++.h>

using namespace std;
long long int YEYE[505][505], BLOG[505][505], yeye[505][505], blog[505][505];

int n, m;

int martian( int x1, int y1, int x2, int y2 )
{
	long long int sum = 0;
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	memset(yeye, 0, sizeof(yeye));
	memset(blog, 0, sizeof(blog));
	for( int i = x1; i < x2; i++ )
		for( int j = y1; j < y2; j++ )
		{
			yeye[i][j] = YEYE[i][j];
			blog[i][j] = BLOG[i][j];
			sum += yeye[i][j];
		}
	for( int i = x1; i < x2; i++ )
	{
		for( int j = y2; j >= y1; j-- )
		{
			if( i == x1 && j== y2 - 1)
				continue;
			else
				if( i==x1 )
				{
					yeye[x1][j] +=yeye[x1][j+1];
					blog[x1][j] +=blog[x1][j+1];
				}
				else
					if( j==y2-1)
					{
						yeye[i][j] += yeye[i-1][j];
						blog[i][j] += blog[i-1][j];
					}
					else
					{
						blog[i][j] = blog[i][j] + blog[i-1][j] + blog[i][j+1] - blog[i-1][j+1];
						yeye[i][j] = yeye[i][j] + yeye[i-1][j] + yeye[i][j+1] - yeye[i-1][j+1];
					}
		}
	}

	for( int i = x1; i < x2; i++ )
	{
		for( int j = y1; j < y2; j++ )
		{
			yeye[i][j] = sum - yeye[i][j];			
		}
	}

	long long int maxi = 0;

	vector <pair<int,int> > temp;

	for( int i = x1; i < x2; i++ )
	{
		for( int j = y1; j < y2; j++ )
		{
			if( maxi == yeye[i][j] + blog[i][j] )
			{
				temp.push_back(make_pair(i,j));
			}
			else if( maxi < yeye[i][j] + blog[i][j] )
				{
					temp.clear();
					temp.push_back(make_pair(i,j));
					maxi = yeye[i][j] + blog[i][j];
				}			
		}
	}

	long long ans = 0;
	for( int i = 0; i < temp.size(); i++ )
	{
		cout<<temp[i].first<<" "<<temp[i].second<<endl; 
		if( temp[i].second == 0 && temp[i].first == x2 - 1)
			continue;

		if( temp[i].second == 0 )
			ans = max( maxi + martian(temp[i].first + 1,temp[i].second,x2,y2), ans);
		else
			if( temp[i].first == x2 - 1)
				ans = max( maxi + martian(x1,y1,temp[i].first,temp[i].second), ans);
			else
				ans = max(maxi + martian(x1,y1,temp[i].first,temp[i].second) + martian(temp[i].first + 1,temp[i].second,x2,y2), ans);
	}
	cout<<ans<<endl;
	return ans;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t = 1;
	while(1)
	{
		int temp;
		cin>>n>>m;

		if( n==0 && m==0)
			return 0;

		long long int sum = 0;

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				cin>>YEYE[i][j];	

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				cin>>BLOG[i][j];

		cout<<martian(0,0,n,m)<<endl;
	}
}