#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    string t = "#";
    for( int i = 0; i < s.length(); i++ )
    {
        t += s.substr(i,1) + "#";
    }
    
    vector <int> P ( 2*t.length(), 0 );

    int C = 0, R = 0;

    for( int i = 1; i < t.length() - 1; i++ )
    {
    	int imirror = 2*C - i;

    	if( R > i )
    		P[i] = min( R - i, P[imirror] );

    	while( t[ i + 1 + P[i] ] == t[ i - 1 - P[i] ] )
    		P[i]++;

    	if( i + P[i] > R )
    	{
    		R = i + P[i];
    		C = i;
    	}

    }

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < t.length() - 1; i++) 
    {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << " "<<centerIndex<<"\n";
    cout<<s.substr( (centerIndex - maxPalindrome) / 2, maxPalindrome)<<endl;
}