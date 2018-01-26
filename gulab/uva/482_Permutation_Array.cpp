#include <bits/stdc++.h>
#include <cstdio>
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define all(c) (c).begin(),(c).end() 
#define size 100000
using namespace std;
typedef pair<int,string> pif;

int main(){
	int t;
	cin>>t;
	char s[size];
	char *p;
	int y=0;
	while(t--){
		fgets(s,size - 1,stdin);
		fgets(s,size - 1,stdin);
		fgets(s,size - 1,stdin);
		pif x;
		// cout<<"hi"<<s<<endl;
		p = strtok(s," ");
		vector<pif> v;
		while(p!=NULL)sscanf(p,"%d",&x.first),v.push_back(x),p = strtok(NULL," ");
		tr(v,i) cin>> i->second;
		sort(all(v));
		if(y)
			cout<<endl;
		y=1;
		tr(v,i) cout << i->second<<endl;
	}
	return 0;
}