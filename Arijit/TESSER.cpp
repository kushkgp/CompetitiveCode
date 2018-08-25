#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	
	while(T--)
	{

		string n, t;
		int temp, temp2, l = 0;
		
		cin>>l>>temp;

		n = "";

		for( int i = 1; i < l ; i++ )
		{
			cin>>temp2;
			if( temp < temp2 )
				n = n + "G";
			else
				if( temp == temp2 )
					n = n + "E";
				else
					n = n + "L";

			temp = temp2;
		}

		cin>>t;

		string s = t + "#" + n;

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

		int flag = 0;
		for( int i = 1; i < s.length(); i++ )
		{
			if(F[i] == t.length())
				flag = 1;
		}

		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}