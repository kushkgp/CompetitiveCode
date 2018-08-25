#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T = 1;
	while(T--)
	{
		int n1, n2, m1, m2;

		cin>>n1>>n2;
		vector <string> map(n1);

		for( int i = 0; i < n1; i++ )
			cin>>map[i];

		cin>>m1>>m2;
		vector <string> marsh(m1);

		for( int i = 0; i < m1; i++ )
			cin>>marsh[i];

		vector <pair<int,int> > ans;

		swap(m1,n1);
		swap(n2,m2);
		// cout<<"HELLO"<<n1<<m1<<n2<<m2<<endl;

		for( int k = 0; k <= n1 - m1; k++ )
		{
			vector <vector <int> > F ( m1 + 1, vector <int>( n2 + m2 + 5, 0) );
			
			for( int l = 0; l < m1; l++)
			{
				string t = map[l];
				string n = marsh[k + l];

				string s = t + "#" + n;

				// cout<<s<<" "<<k<<" "<<l<<endl;
				F[l][0] = 0;

				for( int i = 1; i < s.length(); i++ )
				{
					int j = F[l][i-1];

					while( j > 0 && s[i] != s[j] )
						j = F[l][j-1];

					if( s[i] == s[j] )
						j++;

					F[l][i] = j;
				}

			}

			// for( int i = 0; i < m1; i++ )
			// {
			// 	for( int j = m2; j < n2 + m2 + 1; j++ )
			// 		cout<<F[i][j]<<" ";
			// 	cout<<endl;
			// }

			// cout<<endl;
			for( int i = m2 + 1; i < n2 + m2 + 1; i++ )
			{
				int flag = 0;
				for( int j = 0; j < m1; j++ )
					if( F[j][i] != m2 )
						flag = 1;

				if( !flag )
					ans.push_back(make_pair(k+1,i - 2*m2 + 1));
			}
			// cout<<endl;
		}
		
		for( int i = 0; i < ans.size(); i++ )
			cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<endl;

		if(ans.size() == 0 )
			cout<<"NO MATCH FOUND..."<<endl;
	}
}