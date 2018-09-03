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

void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

int BIT [200005];
int n;
int query( int index )
{
	if( index == 0 )
		return 0;

	int ans = 0;
	while( index > 0 )
	{
		ans += BIT[index];
		index -= index & (-index);
	}
	return ans;
}

void update( int index, int val )
{
	while( index <= n)
	{
		BIT[index] += val;
		index += index & (-index);
	}
}

int bin( int l, int r, int req )
{
	if( l >= r )
		return l;
	int mid = (l+r)>>1;
	int left = query(mid) - query(l-1);
	int right = query(r) - query(mid);
	int ans;
	if( req > left )
		ans = bin( mid + 1, r, req - left );
	else
		ans = bin( l, mid, req );
	return ans;
}

// int bin( int l, int r, int req )
// {
// 	int mid, left, right;

// 	while( l < r )
// 	{
// 		mid = (l+r)>>1;
// 		left = query(mid) - query(l-1);
// 		right = query(r) - query(mid);

// 		if( req > left )
// 		{
// 			l = mid + 1;
// 			req = req - left;
// 		}
// 		else
// 			r = mid;
// 	}

// 	return l;
// }

int main()
{
	int t;
	fastscan(t);

	while(t--)
	{
		fastscan(n);
	 	for( int i = 1; i <= n; i++ )
	 		update(i,1);
	 	int curr = 0, free = 0, req;

	 	int ans[n+1], in[n+1];
	 	for( int i = 1; i <= n; i++ )
	 		fastscan(in[i]);

	 	for( int i = n; i >= 1; i-- )
	 	{
	 		ans[i] = bin(1, n, i - in[i]);
	 		update( ans[i], -1 );
	 	}

	 	for( int i = 1; i <= n; i++ )
	 		printf("%d ",ans[i]);
	 	printf("\n");
	}
}