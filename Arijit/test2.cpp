#include<bits/stdc++.h>
using namespace std;

void computeKMP(vector<int> &F,string s,int n)
{
	F[0] = 0;
	for(int i=1;i<n;i++)
	{
		int j =F[i-1];
		while(j>0 && s[j]!=s[i])
			j = F[j-1];
		if(s[j]==s[i])
			j++;
		F[i] = j;
	}
}

int main()
{
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	vector<string> v(n1);
	getchar();
	for(int i=0;i<n1;i++)
		getline(cin,v[i]);
	int m1,m2;
	scanf("%d%d",&m1,&m2);
	getchar();
	vector<string> grid(m1);
	for(int i=0;i<m1;i++)
	{
		getline(cin,grid[i]);
	}
	// for(int i=0;i<n1;i++)
	// 	cout<<v[i]<<endl;
	// for(int i=0;i<m1;i++)
	// 	cout<<grid[i]<<endl;
	vector<int> ind[m1];
	vector<int> F(n2+m2+1);

	for(int i=0;i<= m1-n1;i++)
	{
		string text = v[0] + "#" + grid[i];
		computeKMP(F,text,n2+m2+1);
		// cout<<"not dumped"<<endl;
		int t = n2+m2+1;
		for(int j=0;j<t;j++)
		{
			if(F[j] == n2)
			{
				ind[i].push_back(j-(2*n2));
				// cout<<i<<" "<<(j-(2*n2));
			}
		}
	}

	vector<pair<int,int> > ans;
	for(int i=0;i<=m1-n1;i++)
	{
		int n = ind[i].size();
		if(n==0)
			continue;
		for(int j=0;j<n;j++)
		{
			int k = ind[i][j];
			int SET = 1;
			for(int t=1;t<n1;t++)
			{
				if(grid[i+t].substr(k,n2) != v[t])
				{
					SET = 0;
					break;
				}

			}
			if(SET == 1)
				ans.push_back(make_pair(i+1,k+1));
		}
	}
	if(ans.size() == 0)
		cout<<"NO MATCH FOUND..."<<'\n';
	else
	{
		int sz = ans.size();
		for(int i=0;i<sz;i++)
			cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<'\n';
	}
}