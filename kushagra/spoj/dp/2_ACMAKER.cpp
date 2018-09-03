/*
	Author		:	Kushagra Aggarwal
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf 1e9
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
	while(1){
		int n;
		cin >> n;
		if(n==0)
			return 0;
		map<string,int> insig;

		while(n--){
			string a;
			cin >> a;
			insig[a] = 1;
		}

		getline(cin,inp);
		while(1){
			string inp;
			getline(cin,inp);
			if(inp == "LAST CASE")
				break;
			stringstream s(inp);
			string word, ACM;
			s >> ACM;
			vector<string> wordlist;
			while(s >> word){
				if(insig.find(word)!=insig.end()){
					wordlist.pb(word);
				}
			}
			
		}
	}


}