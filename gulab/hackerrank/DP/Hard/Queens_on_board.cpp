/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi block;
vvi qpos;
vvi dp;
int n,m;
const int MOD = 1000000007;

typedef struct mask{
	int vmsk;
	int lmsk;
	int rmsk;
	mask(){
		vmsk = lmsk = rmsk = 0;
	}
	int to_int(){
		return (vmsk<<2*m)|(lmsk<<m)|rmsk;
	}
}mask;

bool compatible(int pos, mask & msk){
	int x = 0;
	x = msk.vmsk|msk.lmsk|msk.rmsk;
	return  !(pos & x);
}

mask nextmsk(int pos, mask & msk, int b){
	mask nmsk;
	nmsk.vmsk = (~b)&(msk.vmsk|pos);
	nmsk.lmsk = (~b)&(msk.lmsk|pos);
	nmsk.rmsk = (~b)&(msk.rmsk|pos);
	nmsk.rmsk>>=1;
	nmsk.lmsk<<=1;
	nmsk.lmsk&=(~(1<<m));
	return nmsk;
}


int solve(int i,mask msk){
	if(i==n)
		return 1;
	if(dp[i][msk.to_int()]!=-1)
		return dp[i][msk.to_int()];
	int result = 0;
	for (int j = 0; j < qpos[i].size(); ++j)
	{
		if(compatible(qpos[i][j],msk)){
			result += solve(i+1,nextmsk(qpos[i][j],msk,block[i]));
			result %= MOD;
		}
	}
	dp[i][msk.to_int()] = result;
	return result;
}

bool check(int pos, int b){
	vi c(m,0);
	for (int i = 0; i < m; ++i)
	{
		if(pos&(1<<i))
			c[i] = 1;
		else if(b&(1<<i))
			c[i] = 2;
	}

	for (int i = 0; i < m; ++i)
	{
		if(c[i]==1){
			i++;
			while(i<m&&!c[i])
				i++;
			if(i<m&&c[i]==1)
				return false;
		}
	}
	return true;
}

void set_qpos(){
	qpos.resize(n,vi());
	dp.resize(n,vi(1<<3*m,-1));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (1<<m); ++j)
		{
			if((!(block[i] & j))&&check(j,block[i])){
				qpos[i].pb(j);
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		block.resize(n,0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				char c;
				cin>>c;
				if(c=='#')
					block[i]|=(1<<m-j-1);
			}
		}
		set_qpos();
		// cout<<qpos[0][3]<<endl;
		cout<<(solve(0,mask())+MOD-1)%MOD<<endl;
		block.clear();
		qpos.clear();
		dp.clear();
	}
	return 0;
}