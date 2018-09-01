/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <message.h>
#include "rps.h"

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

const int nd = NumberOfNodes();
const int id = MyNodeId();

pii GetSegment(ll size){
	return mp(size*id/nd, size*(id+1)/nd-1);
}

bool operator<(const pair<int,char> &a, const pair<int,char> &b){
	if((a.ss=='R'&&b.ss=='S')||(a.ss=='S'&&b.ss=='P')||(a.ss=='P'&&b.ss=='R'))
		return true;
	if(a.ss==b.ss)
		return true;
	return false;
}

int main(){
	ll n = GetN();
	int last_machine = 1<<(int)log2(nd);
	if((1<<n)<last_machine)
		last_machine = 1<<n;
	if(id>=last_machine)
		return 0;
	{
		pii segment = mp(id*((1<<n)/last_machine), (id+1)*((1<<n)/last_machine)-1);
		int x = segment.ss-segment.ff+1;
		vector<pair<int,char> > v(x);
		F1(i, segment.ff, segment.ss)
			v[i-segment.ff] = mp(i, GetFavoriteMove(i));
		while(x>1){
			F1(i, 0, x/2-1)
				v[i] = (v[i<<1]<v[i<<1|1])?v[i<<1]:v[i<<1|1];
			x>>=1;
		}
		PutInt(0, v[0].ff);
		PutChar(0, v[0].ss);
		Send(0);
	}
	if(id==0){
		int x = last_machine;
		vector<pair<int,char> > v(x);
		F1(i, 0, x-1){
			Receive(i);
			v[i].ff = GetInt(i);
			v[i].ss = GetChar(i);
		}
		while(x!=1){
			F1(i, 0, x/2-1)
				v[i] = (v[i<<1]<v[i<<1|1])?v[i<<1]:v[i<<1|1];
			x>>=1;
		}
		cout<<v[0].ff<<endl;
	}
}