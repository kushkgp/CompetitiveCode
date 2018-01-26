#include <bits/stdc++.h>
#define size 100000
using namespace std;
typedef long long int ll;

int main(){
	int t;
	cin>>t;
	char s[size];
	map<char,int> mymap;
	while(t--){
		int k;
		cin>>k;
		char c;
		int v;
		while(k--) cin>>c>>v, mymap[c]=v;
		int m;
		ll cost=0;
		cin>>m;
		fgets(s,size,stdin);
		while(m--){
			fgets(s,size,stdin);
			for (int i = 0; i < strlen(s); ++i)
				if(mymap.find(s[i])!=mymap.end())
					cost+=mymap[s[i]];
		}
		printf("%0.2lf$\n",(double)cost/100);
		mymap.clear();
	}
}