/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <message.h>
#include "oops.h"

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()

#define F1(x,y,z) for(auto x = y; x <= z; x++)
#define F2(x,y,z) for(auto x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int n = NumberOfNodes();
const int id = MyNodeId();

pii GetSegment(ll size){
	return mp(size*id/n, size*(id+1)/n-1);
}

int main(){
	int size = GetN();
	pii segment = GetSegment(size);
	ll mi = INT_MAX, ma = INT_MIN;
	{
		F1(i,segment.ff, segment.ss)
			mi = min(mi, GetNumber(i)), ma = max(ma, GetNumber(i));
		PutLL(0, mi);
		PutLL(0, ma);
		Send(0);
	}
	mi = INT_MAX, ma = INT_MIN;
	if(id == 0){
		F1(i, 0, n-1){
			Receive(i);
			mi = min(mi, GetLL(i));
			ma = max(ma, GetLL(i));
		}
		cout<<ma - mi<<endl;
	}
}
