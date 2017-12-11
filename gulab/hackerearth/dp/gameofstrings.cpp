#include <bits/stdc++.h>
using namespace std;

string remove_vowels(string & s){
	string temp = "";
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u');
		else
			temp.append(1,s[i]);
	}
	return temp;
}

int lcs(string & s1,string & s2){
	int dp[s1.length()][s2.length()];
	for (int i = 0; i < s1.length(); ++i)
	{
		for (int j = 0; j < s2.length(); ++j)
		{
			if(s1[i]==s2[j]){
				dp[i][j] = 1;
				if(i&&j)
					dp[i][j]+=dp[i-1][j-1];
			}
			else{
				dp[i][j] = 0;
				if(i && dp[i][j]<dp[i-1][j])
					dp[i][j] = dp[i-1][j];
				if(j && dp[i][j]<dp[i][j-1])
					dp[i][j] = dp[i][j-1];
			}
		}
	}
	return dp[s1.length()-1][s2.length()-1];
}


int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	s1 = remove_vowels(s1);
	s2 = remove_vowels(s2);
	if(s1.length() && s2.length())
		cout<<lcs(s1,s2)<<endl;
	else cout<<"0"<<endl;
	return 0;
}