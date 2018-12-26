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
#define print(test_case, ans) cout << "Case #" << test_case << ": " << ans << "\n"

using namespace std;
typedef unsigned long long int ll;
template <typename x> using v = vector<x>;
template <typename x> using vv = v<v<x> >;

class Trie
{
private:
	vector<vector<int> > x;									// stores respective nodes
	vector<int> isword;										// stored is it word? (change it to store no. of words)
	vector<int> dummy;										// dummy used for initializing every node of the trie(-1 for every character)
	int next;												// denotes the min index which is not given yet a.k.a total nodes
	void increase_size(){
		x.push_back(dummy);
		isword.push_back(0);
	}
public:
	void insert(const string& s){
		int v = 0;
		for (int i = 0; i < s.length();i++){
			if(x[v][s[i]-'0'] == -1){
				increase_size();
				x[v][s[i]-'0'] = next++;
			}
			v = x[v][s[i]-'0'];
		}
		isword[v] = 1;										// change it isword[v]++ to store no. of words 
	}
	Trie(){
		dummy.resize(2,-1);
		increase_size();
		next = 1;
	}
	ll ans(int v, int l){
		if(isword[v])
			return 0;
		ll a = 0;
		if(x[v][0] == -1)
			a+=(((ll)1)<<l);
		else
			a+=ans(x[v][0], l-1);
		if(x[v][1] == -1)
			a+=(((ll)1)<<l);
		else
			a+=ans(x[v][1], l-1);
		return a;
	}
};

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		Trie T;
		F1(i, 0, p-1){
			string s;
			cin>>s;
			F1(j, 0, (int)s.size()-1)
				s[j] = (s[j]=='R'?'0':'1');
			T.insert(s);
		}
		print(cnt++, T.ans(0, n-1));
	}
}