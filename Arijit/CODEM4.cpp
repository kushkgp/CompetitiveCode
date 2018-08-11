#include <bits/stdc++.h>

using namespace std;

long long int LIS[1005], LDS[1005];

vector <int> arr;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n, temp;
		cin>>n;

		arr.clear();

		for( int i = 0; i < n; i++ )
		{
			cin>>temp;
			arr.push_back(temp);
		}

		LIS[0] = 1;
		for( int i = 1; i < n; i++ )
		{
			temp = 0;
			for( int j = 0; j < i ; j++ )
			{
				if( arr[j] < arr[i] )
					temp = max( temp, LIS[j] );
			}

			LIS[i] = 1 + temp;
		}


		LDS[n-1] = 1;
		for( int i = n-2; i >= 0; i-- )
		{
			temp = 0;
			for( int j = n-1; j > i ; j-- )
			{
				if(arr[j]<arr[i])
				temp = max( temp, LDS[j] );
			}

			LDS[i] = 1 + temp;
		}

		long long int maxi = 0;
		for( int i = 0; i< n; i++)
			maxi = max(maxi, LDS[i] + LIS[i] - 1);

		cout<<maxi<<endl;
	}
}