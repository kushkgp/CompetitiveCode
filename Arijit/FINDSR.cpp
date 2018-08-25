#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		string s;
		cin>>s;

		if( s == "*" )
			break;

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

		// for( int i = 0; i < s.length(); i++ )
		// 	cout<<F[i]<<" ";
		// cout<<endl;

		int k = s.length() - F[s.length() - 1 ];

		if( s.length() % k == 0 )
			cout<<s.length()/k<<endl;
		else
			cout<<"1"<<endl;
	}
}