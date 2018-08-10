#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<string> words;

void ToLower(int a)
{
	string s;
	int n = words[a].size();

	for(int i=0;i<n;i++)
	{
		char c = words[a][i];
		char a = (char) (c + ('z' - 'Z'));
		s.pb(a);
	}
	words[a] = s;
}


int find_count(string a,int i)
{
	string word = words[i];
	int n = a.size();
	int m = word.size();
	// cout<<a<<" "<<word<<endl;
	int dp[n+1][m+1];
	for(int i=0;i<=m;i++)
		dp[0][i] = 1;
	for(int i=1;i<=n;i++)
		dp[i][0] = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i-1] == word[j-1])
				dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
			else
				dp[i][j] = dp[i][j-1];
		}

	return dp[n][m];
}

int find_abbr()
{
	int n = words.size() - 1;
	int m = words[0].size();
	string abbr = words[0];
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		memset(dp[i],0,sizeof dp[i]);
	dp[0][0] = 1;
	for(int i=0;i<n;i++)
		for(int j =0;j<=m;j++)
		{
			for(int k = j+1;k<=m;k++)
			{
				int cnt = find_count(abbr.substr(j,k-j),i+1);
				dp[i+1][k] += cnt * dp[i][j];
			}
		}
	return dp[n][m];
}

int main()
{
	map<string,int> stop;

	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		stop.clear();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			stop[s] = 1;
		}
		getchar();
		while(true)
		{
			words.clear();
			string a;
			getline(cin,a);
			if(a == "LAST CASE")
				break;
			char delimeter(' ');
			string tok;
			stringstream ss(a);
			while(getline(ss,tok,delimeter))
				{
					if(stop.find(tok) == stop.end())
						words.pb(tok);
				
				}
			string out = words[0];
			ToLower(0);
			// for(int i=0;i<words.size();i++)
			// 	cout<<words[i]<<endl;
			int ans = find_abbr();
			if(ans == 0)
				cout<<out<<" is not a valid abbreviation"<<endl;
			else
				cout<<out<<" can be formed in "<<ans<<" ways"<<endl;
		}
	}

}