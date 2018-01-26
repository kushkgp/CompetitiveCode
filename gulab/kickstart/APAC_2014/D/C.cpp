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
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t, cnt =1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<string,string> m;
		map<string,int> s;
		F1(i,0,n-1){
			string a,b;
			cin>>a>>b;
			m[a] = b;
			if(s.find(b)==s.end() || s[b])
				s[b] = 0;
			if(s.find(a)==s.end())
				s[a] = 1;
		}
		string st;
		for(auto & it: s){
			if(it.ss){
				st = it.ff;
				break;
			}
		}
		printf("Case #%d: ", cnt++);
		while(!m.empty()){
			cout<<st<<"-"<<m[st]<<" ";
			string temp = st;
			st = m[st];
			m.erase(temp);
		}
		cout<<endl;
	}
}