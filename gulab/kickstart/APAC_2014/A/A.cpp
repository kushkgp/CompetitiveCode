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
/*
	no.->possible?,broken,correct
*/

int no[] = {1111110,110000,1101101,1111001,110011,
			1011011,1011111,1110000,1111111,1111011};

int dec(int x){
	int ans = 0;
	for(int pow=1; x; pow*=2,x/=10)
		ans+=pow*(x%10);
	return ans;
}

string bin(int x){
	string ans;
	for(int pow=1,i=0; i<7; i++,pow*=10,x/=2)
		ans+=to_string(x%2);
	reverse(all(ans));
	return ans;
}

int main(){
	int t;
	cin>>t;
	int counter = 1;
	for(int i = 0; i < 10; i++)
		no[i]=dec(no[i]);
	while(t--){
		vector<pair<int,pii> > prev(10,mp(1,mp(0,0)));
		vector<pair<int,pii> > curr(10);
		int n;
		cin>>n;
		while(n--){
			string s;
			cin>>s;
			int x = stoi(s);
			x=dec(x);
			for(int i = 0; i < 10; i++){
				int j = (i+1)%10;
				if(prev[j].ff){
					if(no[i]==(no[i]|x) && !(prev[j].ss.ff&x) && !(prev[j].ss.ss&(no[i]-x))){
						curr[i].ff=1;
						curr[i].ss.ff = prev[j].ss.ff|(no[i]-x);
						curr[i].ss.ss = prev[j].ss.ss|x;
					}
					else
						curr[i].ff=0;
				}
				else
					curr[i].ff=0;
			}
			prev = curr;
		}
		int f = 1;
		string ans;
		for(int i = 0; i < 10; i++){
			int j = (i+9)%10;
			if(curr[i].ff){
				if(!((no[j]&(curr[i].ss.ff^curr[i].ss.ss))==no[j]))
					f=0;
				string temp = bin(no[j]&(~curr[i].ss.ff));
				if(ans!="" && ans!=temp)
					f=0;
				else
					ans = temp;
			}
		}
		printf("Case #%d: ", counter++);;
		if(f)
			cout<<ans;
		else
			cout<<"ERROR!";
		cout<<endl;
	}
}