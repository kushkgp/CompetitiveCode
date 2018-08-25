#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin>>T;
    while(T--)
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

    	while( (i + 1 + P[i] < t.length() && i - 1 - P[i] >= 0 ) && t[ i + 1 + P[i] ] == t[ i - 1 - P[i] ] )
    		P[i]++;

    	if( i + P[i] > R )
    	{
    		R = i + P[i];
    		C = i;
    	}

    }

    int maxPalindrome = 0;
    int centerIndex = 0;

    int count = 1;
    for (int i = 1; i < t.length() - 1; i++) 
    {
        if (P[i] > maxPalindrome)
        {
            maxPalindrome = P[i];
            count = 1;
        }
        else
            if( P[i] == maxPalindrome )
                count++;
    }
    cout << maxPalindrome << " "<<count<<"\n";
    }
}