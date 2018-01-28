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
		int P;
		cin >> P;
		vi S(P,0);

		F1(i,0,P-1){
			cin >> S[i];
		}

		int N;
		cin >> N;

		vvl points(P*N,vl());

		map<string,int> ids;

		vector<string> names;
		
		F1(i,0,N-1){
			int wt;
			cin >> wt;
			F1(j,0,P-1){
				string player;
				cin >> player;
				if(ids.find(player)==ids.end()){
					int id = ids.size();
					ids[player] = id;
					names.pb(player);
				}
				points[ids[player]].pb(((ll)wt)*S[j]);
			}
		}

		int m;
		cin >> m;
		vector<pair<ll, string> > answer;

		F1(i,0,(int)ids.size()-1){
			dsort(points[i]);
			ll score = 0;
			F1(j,0,m-1){
				if(j>=points[i].size())
					break;
				score += points[i][j];
			}
			answer.pb(mp(0-score, names[i]));
		}
		asort(answer);

		cout << "Case #" << C++ << ":"<<  endl;
		int prev_rank = 1;
		int rank = 0;
		F1(i,0,(int)answer.size()-1){
			rank = i+1;
			if(i>0 && i<answer.size() && answer[i].ff == answer[i-1].ff)
				rank = prev_rank;
			else
				prev_rank = rank;
			cout << rank << ": " << answer[i].ss << endl;
		}
	}
}