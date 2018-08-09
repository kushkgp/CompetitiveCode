#include <bits/stdc++.h>
using namespace std;

string s,t,q;
vector <int> vec[26];
long long int LCS()		
{
	int currPos = 0, i=0;
	while (i < t.length())
	{
		int jmp = 0;
		while (isdigit(t[i]))
		{
			jmp = jmp * 10 + t[i] - '0';
			i++;
		}
		
		char ch = t[i] - 'A';
		
		int firstPos = lower_bound(vec[ch].begin(), vec[ch].end(), currPos) -  vec[ch].begin();
		if (firstPos + jmp - 1 >= vec[ch].size())
		      return 0;
		      
		currPos = vec[ch][firstPos + jmp - 1] + 1;
		i++;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n, temp;
		cin>>n>>s;
		
		for( int i = 0; i < 26; i++ )
		{
			vec[i].clear();
		}

		for( int i = 0 ; i < s.length(); i++ )
		{
			vec[s[i]-'A'].push_back(i);
		}

		for( int i = 0; i < n; i++ )
		{
			cin>>t;
			
			if(LCS()==1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}