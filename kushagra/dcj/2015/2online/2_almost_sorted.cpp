/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/
#include <bits/stdc++.h>
#include <message.h>
#include "almost_sorted.h"

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

pair<ll,ll> get_segment(int id, int total_size, int segs){
	return mp((ll)id*total_size/segs, (id+1)*(ll)total_size/segs - 1);
}

int main(){
	int my_id = myid();
	int nodes = get_node_cnt();
	
	int n = NumberOfFiles();
	int k = MaxDistance();

	pair<ll,ll> seg = get_segment(my_id, n, nodes);

	vector<ll> values(0);

	FOR(i,max(seg.F-k,0ll), min(seg.S+k,(ll)n-1)){
		values.pb((ll)Identifier(i));
	}
	sort(all(values));

	int modulus = 1<<20;
	ll ans = 0;
	FOR(i,seg.F,seg.S){
		ans += (ll)(seg.F)*values[i - seg.F + min(seg.F,(ll)k)];
		ans %= modulus;
	}
	puti(0,(int)ans);
	send(0);

	if(my_id==0){
		FOR(i,0,nodes-1){
			int rec;
			recv(i);
			rec = geti(i);
			ans += rec;
			ans %= modulus;
		}
		cout << ans << endl;
	}
}