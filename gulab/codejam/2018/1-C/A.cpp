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
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define F1(x,y,z) for(int x = y; x <= z; x++)
#define F2(x,y,z) for(int x = y; x >= z; x--)
#define MOD 1000000007

using namespace std;
typedef long long int ll;
template <typename X> using v = vector<X>;
template <typename X> using vv = v<v<X> >;
typedef v<int> vi;
typedef v<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;


int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n, l;
		cin>>n>>l;
		v<string> s(n);

		F1(i,0,n-1){
			cin>>s[i];
		}
		printf("Case #%d: ", cnt++);
		int f = 1;
		F1(j,0,l-2 && f){
			map<char, vector<bool> > m;
			v<bool> pr1(26,false);
			v<bool> pr2(26,false);
			F1(i,0,25){
				m.insert(mp('A'+i,v<bool>(26,true)));
			}
			F1(i,0,n-1){
					pr1[s[i][j]-'A'] = true;
					pr2[s[i][j+1]-'A'] = true;
					m[s[i][j]][int(s[i][j+1]-'A')] = false;
			}
			F1(i,0,25 && f){
				if(pr1[i]){
					F1(k,0,25){
						if(pr2[k]){
							if(m[i+'A'][k]){
								f = 0;
								s[0][j] = i+'A';
								s[0][j+1] = k+'A';
								cout<<s[0]<<endl;
								break;
							}
						}
					}
				}
			}
		}
		if(f)
			cout<<"-"<<endl;
	}
}