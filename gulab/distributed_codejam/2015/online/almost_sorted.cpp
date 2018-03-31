/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <message.h>
#include "almost_sorted.h"

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

pair<ll,ll> getSegment(int i, int n, ll size){
	return mp((size*i)/n, (size*(i+1))/n);
}

int main(){
	int n = NumberOfNodes();
	int id = MyNodeId();
	int size = NumberOfFiles();
	int k = MaxDistance();
	const int mod = (1<<20);
	
	// locally sorting and checksum computation
	{
		pair<ll, ll> segment = getSegment(id, n, size);
		vector<ll> v;
		ll left = 0;
		ll checksum = 0;
		F2(i, segment.ff-1, segment.ff-k && i >= 0)
			v.pb(Identifier(i)), left++;
		F1(i, segment.ff, segment.ss-1)
			v.pb(Identifier(i));
		F1(i, segment.ss, segment.ss+k-1 && i < size)
			v.pb(Identifier(i));
		sort(all(v));
		F1(i, left, left+segment.ss-segment.ff-1){
			checksum+= ((ll)(v[i]%mod)*(i-left+segment.ff))%mod;
			checksum%= mod;
		}
		PutLL(0, checksum);
		Send(0);
	}

	// combine all the checksums
	if(id == 0){
		ll checksum = 0;
		F1(i, 0, n-1){
			Receive(i);
			checksum+= GetLL(i);
			checksum%= mod;
		}
		cout<<checksum<<endl;
	}
}