#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int count = 1;
	
	while(t--)
	{

		string n, t;
		cin>>t>>n;

		string s = n + "#" + t;

		vector <int> F ( s.length() + 1);
		F[0] = 0;

		for( int i = 1; i < s.length(); i++ )
		{
			int j = F[i-1];

			while( j > 0 && s[i] != s[j] )
				j = F[j-1];

			if( s[i] == s[j] )
				j++;

			F[i] = j;
		}

		vector <int> ans;

		for( int i = 1; i < s.length(); i++ )
			if(F[i] == n.length())
				ans.push_back(i-2*n.length());


		if( ans.size() != 0 )
		{
			cout<<ans.size()<<endl;
			for( int i = 0; i < ans.size(); i++ )
				cout<<ans[i]+1<<" ";

			cout<<endl;
		}
		else
			cout<<"Not Found"<<endl;

		cout<<endl;
	}
}