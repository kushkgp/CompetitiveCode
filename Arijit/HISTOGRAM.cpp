#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T = 1;
	while(T)
	{
		long long int n, height[100005], maxi = 0, temp = 0, temp2, x;
		stack <long long int> A;

		cin>>n;
		if( n == 0 )
			break;
		
		for( int i = 0; i < n; i++ )
			cin>>height[i];

		A.push(0);
		
		for( int i = 1; i < n; )
		{
			if( A.empty() || height[i] >= height[A.top()] )
				A.push(i++);
			else
			{
				temp2 = A.top();
				A.pop();
				if( A.empty() )
					x = -1;
				else
					x = A.top();

				maxi = max(maxi, height[temp2]*(i - x - 1 ));
			}
		}

		while( !A.empty() )
		{
			temp2 = A.top();
			A.pop();
			if( A.empty() )
				x = -1;
			else
				x = A.top();

			maxi = max(maxi, height[temp2]*(n - x - 1 ));		
		}

		cout<<maxi<<endl;
	}
}