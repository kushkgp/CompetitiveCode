#include <bits/stdc++.h>

using namespace std;

int main()
{
	int L;
	while(cin>>L)
	{
		vector <int> ans;
		string n;

		cin>>n;

		string s = n + "#";
		char char1;
		vector <int> F ( n.length() + 1, 0 );

		for( int i = 1; i <= n.length() ; i++ )
		{
			int j = F[i-1];

			while( j > 0 && s[i] != s[j] )
				j = F[j-1];

			if( s[i] == s[j] )
				j++;

			F[i] = j;
		}

		for( int i = n.length() + 1; ; i++ )
		{
			getchar(cin,char1);
			cout<<char1<<endl;
			
			if(char1 == '\n')
				break;


			s = s + char1;
			int j = F[i-1];

			while( j > 0 && s[i] != s[j] )
				j = F[j-1];

			if( s[i] == s[j] )
				j++;

			F.push_back(j);
			if(F[i] == n.length())
				ans.push_back(i-2*n.length());
		}

		if( ans.size() != 0 )
		{
			cout<<ans.size()<<endl;
			for( int i = 0; i < ans.size(); i++ )
				cout<<ans[i]<<" ";

			cout<<endl;
		}
		else
			cout<<endl;
	}
}