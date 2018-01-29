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


inline bool check(int x){
	return (x>=0&&x<8);
}

int cut(vvi & v, char type, int x, int y){
	int ans = 0;
	if(type=='N'||type=='P'){
		if(type=='N'){
			F1(i,-2,2)
				F1(j,-2,2)
					if(i&&j&&abs(abs(i)-abs(j))==1)
						if(check(x+i)&&check(y+j)&&v[x+i][y+j])
							ans++;
		}
		else{
			if(check(x+1)&&check(y+1)&&v[x+1][y+1])
				ans++;
			if(check(x+1)&&check(y-1)&&v[x+1][y-1])
				ans++;
		}
	}
	else{
		int h = 0, d = 0, l = 0;
		switch(type){
			case 'K': h = d = l = 1;
				break;
			case 'Q': h = d = 1, l = 7;
				break;
			case 'R': h = 1; l = 7;
				break;
			case 'B': d = 1; l = 7;
				break;
		}
		if(h){
			F1(i,(x+1),min(7,x+l))
				if(v[i][y]){ans++; break;}
			F2(i,(x-1),max(0,x-l))
				if(v[i][y]){ans++; break;}
			F1(i,(y+1),min(7,y+l))
				if(v[x][i]){ans++; break;}
			F2(i,(y-1),max(0,y-l))
				if(v[x][i]){ans++; break;}
		}
		if(d){
			F1(i,-1,1)
				F1(j,-1,1){
					if(i&&j) F1(k,1,min(7,l))
						if(check(x+i*k)&&check(y+j*k)){
							if(v[x+i*k][y+j*k]){
								ans++;break;
							}
						}
						else break;
				}
		}
	}
	return ans;
}

int main(){
	int t, cnt = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vvi v(8,vi(8,0));
		map<pii,char> m;
		while(n--){
			string s;
			cin>>s;
			int x = (s[0] - 'A');
			int y = (s[1] - '1');
			char type = s[3];
			m[mp(x,y)] = type;
			v[x][y] = 1;
		}
		int ans = 0;
		for(auto & it : m){
			char type = it.ss;
			pii pos = it.ff;
			ans += cut(v,type,pos.ff,pos.ss);
		}
		printf("Case #%d: %d\n", cnt++, ans);
	}
}