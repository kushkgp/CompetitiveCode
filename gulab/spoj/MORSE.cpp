/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

string pattern[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

void build_state(vvi & state, const string & s){
	for (int i = 0; i < state.size(); ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			bool f = true;
			for (int k = 0; k < pattern[j].size(); ++k)
			{
				if(i+k >= s.length() || pattern[j][k]!=s[i+k]){
					f = false;
					break;
				}
			}
			if(f){
				state[i].pb(j);
			}
		}
	}
}

int x[200001][26];
int isword[200001];

class Trie
{
private:
	int next;
public:
	void insert(string & s){
		int v = 0;
		for (int i = 0; i < s.size();i++){
			if(x[v][s[i]-'A'] == -1)
				x[v][s[i]-'A'] = next++;
			v = x[v][s[i]-'A'];
		}
		isword[v]++; 
	}
	bool search(string & s){
		int v = 0;
		for (int i = 0; i < s.size(); v = x[v][s[i++]-'A'])
			if(x[v][s[i]-'A']==-1)
				return false;
		if(isword[v])
			return true;
		return false;
	}
	Trie(int n){
		for (int i = 0; i <= 20*n; ++i)
		{
			isword[i] = 0;
			for (int j = 0; j < 26; ++j)
			{
				x[i][j]=-1;
			}
		}
		isword[0] = 1;
		next = 1;
	}
	ll parse(const vvi &state, const char* t, int index, int v, int charac, int last){
		if(v==-1 || charac==21)
			return 0;
		if(index == last){
			return isword[v];
		}
		ll result = 0;
		for (int i = 0; i < state[index].size(); ++i)
		{
			int charsize = pattern[state[index][i]].size();
			if(charsize+index<=last)
				result+=parse(state,t,index+charsize,x[v][state[index][i]],charac+1,last);
		}
		return result;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		char s[10005];
		cin>>s;
		int len = strlen(s);
		vvi state;
		state.resize(len,vi());
		build_state(state,s);
		// for (int i = 0; i < state[0].size(); ++i)
		// {
		// 	cout<<char(state[0][i]+65)<<endl;
		// }
		int n;
		cin>>n;
		Trie T(n);
		string temp;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			T.insert(temp);
		}
		ll dp[len+1];
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= len; ++i)
		{
			for (int j = i - 1; j >= i-80 && j>=0; --j)
			{
				dp[i] += T.parse(state,s,j,0,0,i)*dp[j];
			}
		}
		cout<<dp[len]<<endl;
	}
	return 0;
}