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

void ans(const string & s){
	int z[s.length()];
	int l = 0,r = 0;
	int n = s.length();
	for (int i = 1; i < n; ++i)
	{
		if(i>r){
			l = r = i;
			while(r<n && s[r-l]==s[r]) r++;
			z[i] = r-l;
			r--;
		}
		else{
			int k = i - l;
			if(z[k]<r-i+1) z[i]=z[k];
			else{
				l = i;
				while(r<n && s[r-l]==s[r]) r++;
				z[i] = r-l;
				r--;
			}
		}
	}
	int maxz = 0;
	int resl=0;
	for (int i = 1; i < n; ++i)
	{
		if(z[i]==n-i && maxz>=n-i){resl = i; break;}
		maxz = max(maxz,z[i]);
	}
	if(!resl)
		cout<<"Just a legend"<<endl;
	else
		cout<<s.substr(resl,n-resl)<<endl;
}

int main(){
	string s;
	cin>>s;
	ans(s);
}