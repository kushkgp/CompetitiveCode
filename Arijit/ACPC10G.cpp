#include <bits/stdc++.h>

using namespace std;

long long int dp[30][30], origin[30][2], target[30][2];

int distance(int x,int y){
     x = abs(x);
     y = abs(y);
     
     if (x < y) {
        int t = x;
        x = y; 
        y = t;
     }
     
     if(x==1 && y == 0){
        return 3;
     }
     if(x==2 && y == 2){
        return 4;
     }
    
    int delta = x-y;

		if(y>delta){
  		return delta - 2*floor((delta-y)/3);
  	}
  	else{
  		return delta - 2*floor((delta-y)/4);
  	}
}

int main( )
{
    while(1)
    {
        int n;
        cin>>n;
        if( n == 0)
            return 0;

        for( int i = 0; i < n; i++ )
        {
            cin>>origin[i][0]>>origin[i][1];
        }


        for( int i = 0; i < n; i++ )
        {
            cin>>target[i][0]>>target[i][1];
        }

        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                dp[i][j] = distance(origin[i][0] - target[j][0], origin[i][1] - target[j][1]);

        bitmask = 1 << n;
        cout<<recur(n,bitmask)<<endl;
    }
}