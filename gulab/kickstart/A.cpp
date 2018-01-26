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

int main(){
	int t;
	cin>>t;
	int cas = 1;
	while(t--){
		string s;
		cin>>s;
		cout<<"Case #"<<cas++<<": ";
		if(s.size()%2)
			cout<<"AMBIGUOUS"<<endl;
		else{
			int n = s.size();
			int v[n];
			v[1] = s[0]-'A';
			int j = v[1];
			for (int i = 2; i < n; i+=2)
			{
				int x = s[i]-'A';
				j = (x+26-j)%26;
				v[i+1] = j;
			}
			v[n-2] = s[n-1]-'A';
			j = v[n-2];
			for (int i = n-3; i >=0 ; i-=2)
			{
				int x = s[i]-'A';
				j = (x+26-j)%26;
				v[i-1] = j;
			}
			for (int i = 0; i < n; ++i)
			{
				s[i] = char('A'+v[i]);
			}
			cout<<s<<endl;
		}
	}
	return 0;
}