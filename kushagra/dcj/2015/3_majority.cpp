/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/
#include <bits/stdc++.h>
#include <message.h>
#include "majority.h"

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
	int n = GetN();
	int nodes = get_node_cnt();

	pair<ll,ll> seg = get_segment(my_id, n, nodes);

	int moore = 0, candi = 0;
	FOR(i,seg.F, seg.S){
		int vote = GetVote(i);
		if(vote==candi){
			moore++;
		}
		else{
			if(moore==0){
				moore++;
				candi = vote;
			}
			else{
				moore--;
			}
		}
	}

	puti(0,candi);
	puti(0,moore);
	send(0);

	moore = 0;
	candi=0;
	if(my_id==0){
		FOR(i,0,nodes-1){
			int seg_c, seg_m;
			recv(i);
			seg_c = geti(i);
			seg_m = geti(i);

			if(seg_c==candi)
				moore += seg_m;
			else{
				candi = moore>seg_m?candi:seg_c;
				moore = moore>seg_m?(moore-seg_m):(seg_m-moore);
			}
		}
		FOR(i,0,nodes-1){
			puti(i,candi);
			send(i);
		}
	}

	recv(0);
	candi = geti(0);
	moore=0;
	FOR(i,seg.F, seg.S){
		int vote = GetVote(i);
		if(vote==candi){
			moore++;
		}
		
	}
	puti(0,moore);
	send(0);

	int total_votes = 0;
	if(my_id==0){
		FOR(i,0,nodes-1){
			int seg_votes;
			recv(i);
			seg_votes = geti(i);
			total_votes += seg_votes;
		}
		if(total_votes > n/2)
			cout << candi << endl;
		else
			cout << "NO WINNER" << endl;
	}



}