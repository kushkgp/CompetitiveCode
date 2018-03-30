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

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int x = -1;
		F1(i,0,s.length()-1){
			if((s[i]-'0')%2){
				x = i;
				break;
			}
		}
		printf("Case #%d: ", cnt++);
		ll a = stoll(s);
		if(x!=-1){
			if(s[x] == '9'){
				F1(i,x,s.length()-1)
					s[i] = '8';
				cout<<a-stoll(s)<<endl;
			}
			else{
				string a,b;
				a = b = s;
				a[x] = s[x]-1;
				F1(i,x+1,s.length()-1)
					a[i] = '8';
				b[x] = s[x]+1;
				F1(i,x+1,s.length()-1)
					b[i] = '0';
				if(stoll(s)-stoll(a)<stoll(b)-stoll(s))
					cout<<stoll(s)-stoll(a)<<endl;
					// cout<<a<<endl;
				else
					// cout<<b<<endl;
					cout<<stoll(b)-stoll(s)<<endl;
			}
		}
		else
			cout<<0<<endl;
	}
}