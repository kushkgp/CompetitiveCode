#include<bits/stdc++.h>
using namespace std;

int find_subseq(vector<int> &buildings,int n)
{
	int dp_inc[n],dp_dec[n];
	dp_inc[0] = 1;
	for(int i=1;i<n;i++)
	{	dp_inc[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(buildings[j] < buildings[i])
				dp_inc[i] = max(dp_inc[i],1+dp_inc[j]);
		}
	}

	dp_dec[n-1] = 1;
	for(int i=n-2;i>=0;i--)
	{
		dp_dec[i] = 1;
		for(int j=n-1;j>i;j--)
		{
			if(buildings[i] > buildings[j])
				dp_dec[i] = max(dp_dec[i],1+dp_dec[j]);
		}
	}

	int ans = INT_MIN;
	for(int i=0;i<n;i++)
		ans = max(dp_inc[i]+dp_dec[i] - 1,ans);
	return ans;
} 

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> buildings(n);
		for(int i=0;i<n;i++)
			scanf("%d",&buildings[i]);
		printf("%d\n", find_subseq(buildings,n));
	}
}