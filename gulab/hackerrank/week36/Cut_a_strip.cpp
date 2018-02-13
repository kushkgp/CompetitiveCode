/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;

int K;

int max(deque<pii> & q, int x){
	int ind = q.empty()?0:q.back().ss+1;
	while(!q.empty() && q.back().ff <= x)
		q.pop_back();
	q.push_back(mp(x,ind));
	if(ind-q.front().ss>K-1)
		q.pop_front();
	return q.front().ff;
}

int ansx(int n, int m, vvi & A){
	F1(i,1,n-1)
		F1(j,0,m-1)
			A[i][j]+=A[i-1][j];
	int ans = -inf;
	F1(i,0,n-1){
		v<deque<pii> > d(m);
		vi a(m,inf);
		F1(j,i,n-1){
			pii prev = mp(0,0), curr;
			F1(k,0,m-1){
				int x = max(d[k],j?A[j-1][k]:0);
				a[k] = min(a[k],A[j][k]-x);
				int sum = A[j][k] - (i?A[i-1][k]:0);
				curr.ff = sum+(prev.ff>0?prev.ff:0);
				curr.ss = max(sum-a[k]+(prev.ff>0?prev.ff:0),sum+(prev.ss>0?prev.ss:0));
				ans = max3(ans,curr.ff,curr.ss);
				prev = curr;
			}
		}
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m>>K;
	int x = inf;
	int s = 0;
	vvi v1(n,vi(m)),v2(m,vi(n));
	F1(i,0,n-1)
		F1(j,0,m-1){
			cin>>v1[i][j];
			v2[j][i]=v1[i][j];
			s+=v1[i][j];
			x = min(x,v1[i][j]);
		}
	if(x>-1)
		cout<<s-x<<endl;
	else
		cout<<max(ansx(n,m,v1),ansx(m,n,v2))<<endl;
}