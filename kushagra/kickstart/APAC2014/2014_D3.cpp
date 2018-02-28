/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX
#define mod 1000000007

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main(){
	int t,C=1;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vi next(n,-1);
		vi prev(n,-1);
		vector<pair<string,string> > names;
		map<string,int> ft_id;

		F1(i,0,n-1){
			string st, end;
			cin >> st >> end;
			ft_id[st] = names.size();
			names.pb(mp(st,end));
		}

		F1(i,0,n-1){
			string agla = names[i].ss;
			if(ft_id.find(agla)!=ft_id.end()){
				next[i] = ft_id[agla];
				prev[ft_id[agla]] = i;
			}
		}
		int start=-1;
		F1(i,0,n-1){
			if(next[i]==-1){
				start = i;
				break;
			}
		}
		cout << "Case #"<<C++ << ":";
		while(prev[start]!=-1)
			start = prev[start];
		while(next[start]!=-1){
			cout << " " << names[start].ff << "-" << names[start].ss;
			start = next[start];
		}
		cout  << " " << names[start].ff << "-" << names[start].ss;
		cout << endl;
	}
}