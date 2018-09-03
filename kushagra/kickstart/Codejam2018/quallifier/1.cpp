/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define min3(a,b,c) (min(min(a,b),c))
#define max3(a,b,c) (max(max(a,b),c))
#define mod 1000000007
#define inf INT_MAX

#define F2(x,y,z) for(int x = y; x >= z; x--)
#define F1(x,y,z) for(int x = y; x <= z; x++)
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define ss second
#define ff first
#define mp make_pair
#define pb push_back

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;

int value(string P){
	int ans=0;
	int crt=1;
	F1(i,0,(int)P.size()-1){
		if(P[i]=='C')
			crt = crt<<1;
		else if(P[i]=='S')
			ans+=crt;
	}
	return ans;
}

int main(){
	int C = 1;
	int t; cin >> t;
	while (t--) {
		int d;
		string P;
		cin >> d >> P;
		int crt_val = value(P);
		// cout << "Crt-val : " << crt_val << endl;
		int cnt=0;
		int last_shoot_index=(int)P.size()-1;;
		int C_cnt=0;
		F1(i,0,(int)P.size()-1){
			if(P[i]=='C')
				C_cnt++;
		}
		while(crt_val > d){
			last_shoot_index = min((int)P.size()-1,last_shoot_index);
			int crt_c_cnt=0;
			while(last_shoot_index>0 && (P[last_shoot_index]=='C' || P[last_shoot_index-1]=='S')){
				if(P[last_shoot_index]=='C')
					crt_c_cnt++;
				last_shoot_index--;
			}
			if(last_shoot_index==0)
				break;
			crt_val -= 1 << ( C_cnt - crt_c_cnt - 1);
			P[last_shoot_index]='C';
			P[last_shoot_index-1]='S';
			last_shoot_index++;
			cnt++;
			// cout << last_shoot_index << " " << crt_val << " " << d << endl;
		}
		cout << "Case #"<< C++ << ": " << (last_shoot_index==0?"IMPOSSIBLE":to_string(cnt).c_str()) << endl;
	}	

	return 0;
}