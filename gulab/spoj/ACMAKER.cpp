#include <bits/stdc++.h>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
using namespace std;

int solve(const string & s, const vector<string> & sent){
	int f = 0;
	int dp[2][s.length()];
	int x = sent.size()-1;
	memset(dp[!f],0,sizeof(dp[f]));
	tr(sent,word){
		int check = 0;
		memset(dp[f],0,sizeof(dp[f]));
		for (int i = 0; i < (*word).length(); ++i)
		{
			for (int j = s.length()-1; j >= 0; --j)
			{
				dp[f][j] = dp[f][j];
				if(!(s.length()-1-j < x) && (sent.size() - x - 1 <= j)){
				if((*word)[i] == s[j]){
					if(j) dp[f][j] += dp[!f][j-1]+dp[f][j-1];
					else dp[f][j]++;
					check = 1;
				}}
				// cout<<(*word)[i]<<" "<< s[j]<<" "<<dp[f][j] <<endl;
			}
		}
		f^=1;
		x--;
		if(!check){
			// cout<<"hi"<<endl;
			return 0;
		}
	}
	return dp[!f][s.length()-1];
}

int main(){
	int n;
	cin>>n;
	while(n){
		set< string > st;
		string s,x;
		while(n--) cin>>s, st.insert(s);
		cin>>s;
		while(1){
			cin>>x;
			vector< string > sent;
			if(s == string("LAST"))
				if(x == string("CASE")) break;
			while((int)x[0] >= 97){
				if(st.find(x) == st.end())
					sent.push_back(x);
				cin>>x;
			}
			string g =s;
			for (int i = 0; i < s.length(); ++i)
			{
				s[i] = tolower(s[i]);
			}
			int y = solve(s,sent);
			if(y)
				cout<<g<<" can be formed in "<<y<<" ways"<<endl;
			else
				cout<<g<<" is not a valid abbreviation"<<endl;
			s=x;
		}
		cin>>n;
	}
	return 0;
}