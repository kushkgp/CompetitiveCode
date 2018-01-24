/*
	Author		:	Gulab Arora
	Institute	:	IIT Kharagpur
*/

#include <bits/stdc++.h>

#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define inf INT_MAX

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t,cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		char c[102];
		fgets(c,101,stdin);
		string s;
		for(int i = 0; i < n; i++){
			fgets(c,101,stdin);
			string temp(c);
			if(temp[temp.length()-1]=='\n')
				temp.resize(temp.length()-1);
			if(temp<s)
				ans++;
			else
				s=temp;
		}
		printf("Case #%d: %d\n", cnt++, ans);
	}
}