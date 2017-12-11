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

int ans1(int q){
	string s[2];
	cin>>s[0]>>s[1];
	int m=0;
	for (int i = 0; i < q; ++i)
	{
		if(s[0][i]==s[1][i])
			m++;
	}
	int s1,ans;
	cin>>s1;
	if(s1<=m){
		ans = s1+q-m;
	}
	else{
		ans = m+q-s1;
	}
	return ans;
}

int ans2(int q){
	string s[3];
	cin>>s[0]>>s[1]>>s[2];
	int a=0,b=0,c=0,d=0;
	for (int i = 0; i < q; ++i)
	{
		if(s[0][i]==s[1][i]){
			if(s[0][i]!=s[2][i])
				b++;
		}
		else{
			if(s[0][i]==s[2][i]){
				c++;
			}
			if(s[1][i]==s[2][i]){
				d++;
			}
		}
	}
	int s1,s2;
	cin>>s1>>s2;
	return min(3*s1-3*d-2*s2+2*c+b,2*s1-2*d-s2+c+b);
}


int main(){
	int t;
	cin>>t;
	int cas = 1;
	while(t--){
		int n,q;
		cin>>n>>q;
		cout<<"Case #"<<cas++<<": ";
		if(n==1)
			cout<<ans1(q)<<endl;
		else
			cout<<ans2(q)<<endl;
	}
	return 0;
}