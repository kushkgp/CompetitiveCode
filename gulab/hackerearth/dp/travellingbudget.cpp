#include <bits/stdc++.h>
using namespace std;

typedef struct backedge
{
	int u;
	int I,c;
}edge;


void ans(int n,int m,int B){
	std::vector<edge> e[n+1];
	int x,y;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d",&x,&y);
		edge temp;
		temp.u=x;
		scanf("%d %d",&temp.c,&temp.I);
		e[y].push_back(temp);
	}

	int dp[n+1][B+1];
	memset(dp,0,sizeof(dp));
	for (int i = 0; i <=B; ++i)
	{
		dp[0][i]=0;
	}
	for (int i = 2; i <= n; ++i)	// for every vertex
	{
		for (int j = 0 ; j <= B; ++j)	// for every value of money
		{
			dp[i][j]=INT_MAX;
			if(j && dp[i][j-1]!=-1){
				dp[i][j]=dp[i][j-1];
			}
			for (std::vector<edge>::iterator temp = e[i].begin(); temp != e[i].end(); temp++)		// for every node temp which has directed edge to node i
			{
				if(j>=temp->c)
					if(dp[temp->u][j-temp->c]!=-1){
						dp[i][j] = min(dp[i][j],dp[temp->u][j-temp->c]+temp->I);
						// cout<<"hello"<<i<<" "<<temp->u<<" "<<dp[i][j]<<" "<<dp[temp->u][j-temp->c]+temp->I<<endl;
					}

			}
			if(dp[i][j]==INT_MAX)
				dp[i][j]=-1;
		}
	}
	int q;
	scanf("%d",&q);
	int u,cost;
	while(q--){
		scanf("%d %d",&u,&cost);
		printf("%d\n", dp[u][cost]);
	}
}

int main(){
	int t;
	int n,m;
	int B;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&B);
		ans(n,m,B);
	}
}