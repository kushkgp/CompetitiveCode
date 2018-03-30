/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#include <message.h>
#include "sandwich.h"

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

pair<ll, ll> getSegment(int i, int n, ll size){
	return mp((size*i)/n, (size*(i+1))/n);
}

int main(){
	int n = NumberOfNodes();
	int size = GetN();
	int id = MyNodeId();

	// compute locally
	ll tot = 0, lmax = 0, rmax = 0, imax = 0;
	{
		pair<ll, ll> segment = getSegment(id, n, size);
		ll dp = 0;
		F1(i,segment.ff, segment.ss-1){
			int x = -GetTaste(i);
			tot+=x;
			dp = dp>0?dp+x:x;
			imax = max(imax, dp);
			lmax = max(lmax, tot);
		}
		tot = 0;
		F2(i,segment.ss-1, segment.ff){
			int x = -GetTaste(i);
			tot+=x;
			rmax = max(rmax, tot);
		}
		PutLL(0, tot);
		PutLL(0, lmax);
		PutLL(0, rmax);
		PutLL(0, imax);
		Send(0);
	}

	// dp on received data
	tot = lmax = rmax = imax = 0;
	if(id==0){
		F1(i,0,n-1){
			Receive(i);
			ll ttot = GetLL(i);
			ll tlmax = GetLL(i);
			ll trmax = GetLL(i);
			ll timax = GetLL(i);
			imax = max3(imax, timax, rmax+tlmax);
			lmax = max(lmax, tot+tlmax);
			rmax = max(trmax, ttot+rmax);
			imax = max3(imax, lmax, rmax);
			tot+=ttot;
		}
		cout<< imax-tot <<endl;
	}
	return 0;
}