/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/
#include <bits/stdc++.h>
#include <message.h>
#include "sandwich.h"

#define F first
#define S second

#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)

#define all(x) (x).begin(), (x).end()
#define allr(c) (c).rbegin(),(c).rend()

#define sz(x) int(x.size())

#define inf 1e9
#define mod 1000000007

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))

#define pb push_back
#define mp make_pair

#define get_node_cnt NumberOfNodes
#define myid MyNodeId
#define putl PutLL
#define puti PutInt
#define putc PutChar
#define send Send
#define recv Receive
#define getl GetLL
#define geti GetInt
#define getc GetChar

using namespace std;

typedef long long int ll;

template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;

typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef v<pii> vpii;

int main(){
	int id = myid();
	int n = GetN();
	int nodes = get_node_cnt();

	int rng_l = id*n/nodes;
	int rng_r = (id+1)*n/nodes;

	ll seg_l, seg_r, seg_ans, seg_tot;
	seg_l = seg_r = seg_ans = seg_tot = 0;

	FOR(i,rng_l,rng_r-1){
		ll crt = -GetTaste(i);
		seg_tot += crt;
		seg_l = max(seg_l,seg_tot);

		seg_r = max(0ll,seg_r+crt);
		seg_ans = max(seg_ans, seg_r);
	}
	putl(0,seg_l);
	putl(0,seg_r);
	putl(0,seg_tot);
	putl(0,seg_ans);

	send(0);

	if(id == 0){
		ll max_l,ans_tot;
		max_l = ans_tot = 0;

		ll tot = 0;
		FOR(i,0,nodes-1){
			// cout << i << endl;
			ll seg_l, seg_r, seg_ans, seg_tot;
			recv(i);
			seg_l = getl(i);
			seg_r = getl(i);
			seg_tot = getl(i);
			seg_ans = getl(i);

			tot+=seg_tot;
			ans_tot = max(ans_tot,max(max_l+seg_l, seg_ans));
			max_l = max(max_l+seg_tot, seg_r);
		}
		cout << -(tot - ans_tot) << endl;
	}

}