#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second 

typedef vector <int> vi;
typedef pair <int, int> pi;
typedef pair <int, pair<int, int > > ppi;
typedef pair <int, pair <int, pair < int, int > > > pppi;
typedef vector <pi> vpi;
typedef vector <ppi> vppi;
typedef vector <pppi> vpppi;
typedef set<pi> spi;
typedef set<ppi> sppi;

int A[205][205];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		if( n==1 )
		{
			cout<<endl;
			continue;
		}

		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				cin>>A[i][j];
 		
 		for(int i=0;i<n;i++)
 		{
            for(int j=i+1;j<n;j++)
            {
                bool check=false;
                
               	for(int k=0;k<n;k++) if(k!=i && k!=j && A[i][k]+A[k][j]==A[i][j]) check=true;
                
                if(!check) printf("%d %d\n",i+1,j+1);
            }
        }
        if( t )
		cout<<endl;

	}
	return 0;
}