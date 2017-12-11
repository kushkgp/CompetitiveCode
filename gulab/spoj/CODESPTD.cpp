/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi block;						/* stores the blocking points(#) */
vvi qpos;						/* stores valid queen placements in row i */
vvi dp;							/* stores the result for a row for a particular mask */
int n,m;
const int MOD = 1000000007;

typedef struct mask{			/* mask will provide information about invalid queen placement */
	int vmsk;					/* vmsk are positions where we can't put queen as there are queens vertical above*/
	int lmsk;					/* lmsk are positions where we can't put queen as there are queens in diagnol right */
	int rmsk;					/* lmsk are positions where we can't put queen as there are queens in diagnol left */
	mask(){
		vmsk = lmsk = rmsk = 0;
	}
	int to_int(){				/* return no.(3*m bits i.e. max 15 bits) representing this mask */
		return (vmsk<<2*m)|(lmsk<<m)|rmsk;
	}
}mask;

bool compatible(int pos, mask & msk){	/* return true if pos doesn't collide with the masks */
	int x = 0;
	x = msk.vmsk|msk.lmsk|msk.rmsk;
	return  !(pos & x);
}

mask nextmsk(int pos, mask & msk, int b){	/* calculate next mask */
	mask nmsk;
	nmsk.vmsk = (~b)&(msk.vmsk|pos);		/* ~b will negate the effect if the mask value is 1 there i.e. */
	nmsk.lmsk = (~b)&(msk.lmsk|pos);		/* # will stop the effect of previous queens if in their vertical or diagnol path */
	nmsk.rmsk = (~b)&(msk.rmsk|pos);
	nmsk.rmsk>>=1;							/* right shift rmsk */
	nmsk.lmsk<<=1;							/* left shift lmsk */
	nmsk.lmsk&=(~(1<<m));
	return nmsk;
}


int solve(int i,mask msk){					/* recursive function */
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
	dp[i][msk.to_int()] = result;			/* store result */
	return result;
}

bool check(int pos, int b){				/* check whether a set of queen placement is compatible with the block */
	vi c(m,0);							/* returns false if two queens can attack each other horizontally in this permutation */
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

void set_qpos(){							/* precomputing the position of queens(qpos[i]) which are compatible with block[i] */
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
					block[i]|=(1<<m-j-1);		/* setting proper bit representing '#'' there */
			}
		}
		set_qpos();
		// subtract the permutation where there is no queen
		cout<<(solve(0,mask())+MOD-1)%MOD<<endl;
		block.clear();
		qpos.clear();
		dp.clear();
	}
	return 0;
}