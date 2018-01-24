#include <bits/stdc++.h>
#define rem 1000000009
using namespace std;

bool won(int x2,int y2){
	if(min(x2,y2)>=10 && max(x2,y2)-min(x2,y2)>=2)
		return true;
	if(max(x2,y2)>10 && min(x2,y2)<10 && max(x2,y2)==11)
		return true;
	return false;
}

int ans(int x1,int y1,int x2,int y2){
	if(x1>x2 || y1>y2 || (min(x2,y2)>=10 && max(x2,y2)-min(x2,y2)!=2) || won(x1,y1)|| !won(x2,y2))
		return -1;
	int dp[x2+1][y2+1];
	for (int i = 0; i <= x2; ++i)
	{
		for (int j = 0; j <=y2 ; ++j)
		{
			dp[i][j]=0;
			if(i==x1&&j==y1)
				dp[i][j]=1;
			if(min(i,j)>=10){
				if(i==j){
					dp[i][j]+=dp[i-1][j];
					dp[i][j]%=rem;
					dp[i][j]+=dp[i][j-1];
				}
				else{
					if(i>j)
						dp[i][j]+=dp[i-1][j];
					else
						dp[i][j]+=dp[i][j-1];
				}
			}
			else{
				if(i && j!=11)
					dp[i][j]+=dp[i-1][j];
				if(j && i!=11)
					dp[i][j]+=dp[i][j-1];
			}
			dp[i][j]%=rem;
		}
	}
	return dp[x2][y2];
}

int main(){
	int t;
	int x1,y1,x2,y2;
	cin>>t;
	int i = 1;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		cout<<"Case "<<i++<<": "<<ans(x1,y1,x2,y2)<<endl;
	}
	return 0;
}