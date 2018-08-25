#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <pair <string, int> > A (n);
        string temp;

        for( int i = 0; i < n; i++ )
        {
            cin>>temp;
            A[i].first = temp;
            A[i].second = i+1;
        }

        stable_sort( A.begin(), A.end() );
        vector <pair <int, int> > ans (n);
        ans[0].first = A[0].second;

        if( A[0].first[0] == A[1].first[0] )
            ans[0].second = A[1].second;
        else
            ans[0].second = -1;

        for( int i = 1; i < n - 1; i++ )
        {
            ans[i].first = A[i].second;
            int maxA = 0, maxB = 0;

            string tempA = A[i-1].first;
            string current = A[i].first;
            string tempB = A[i+1].first;
            while( maxA < min(tempA.length(), current.length()) && tempA[maxA]==current[maxA])
                maxA++;

            while( maxB < min(tempB.length(), current.length()) && tempB[maxB]==current[maxB])
                maxB++;

            if( maxA == maxB )
            {
                if( maxA == 0 )
                    ans[i].second = -1;
                else
                    ans[i].second = min(A[i-1].second, A[i+1].second);
            }
            else
                if( maxA < maxB )
                    ans[i].second = A[i+1].second;
                else
                    ans[i].second = A[i-1].second;
        }

        ans[n-1].first = A[n-1].second;

        if( A[n-1].first[0] == A[n-2].first[0] )
            ans[n-1].second = A[n-2].second;
        else
            ans[n-1].second = -1;

        sort( ans.begin(), ans.end() );

        for( int i = 0; i < n; i++ )
            cout<<ans[i].second<<endl;
    }
    return 0;
}