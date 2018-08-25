#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int count = 1;
	
	while(t--)
	{
		int n;
		cin>>n;

		string s;
		cin>>s;

		vector <int> F ( n + 1);
		F[0] = 0;

		for( int i = 1; i < n; i++ )
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

		cout<<"Test case #"<<count<<endl;
		count++;
		for( int i = 1; i < n; i++ )
		{
			int k = i + 1 - F[ i ];

			if( (i + 1) % k == 0 && (i+1)!=k)
				cout<<i+1<<" "<<(i+1)/k<<endl;
		}

		if(t)
			cout<<endl;
	}
}