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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string s;

ll find(ll x){
	int full = 0;
	int rem = 0;
	F1(i,0,(int)s.length()-1){
		if(s[i]=='B'){
			full++;
			if(i<x%s.length())
				rem++;
		}
	}
	return full*(x/s.length())+rem;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		cin>>s;
		ll i, j;
		cin>>i>>j;
		printf("Case #%d: %lld\n", cnt++, find(j)-find(i-1));
	}
}