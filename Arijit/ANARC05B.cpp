#include <bits/stdc++.h>

using namespace std;

long long int a[11005], b[11005], sum[11005], sum2[11005];
vector <long long int> C;

int main()
{
	int t = 1;
	while(t)
	{
		long long int n, m;
		cin>>n;
		
		// memset(A,0,sizeof(A));
		// memset(B,0,sizeof(B));
		// memset(sum,0,sizeof(sum));
		// memset(sum2,0,sizeof(sum2));

		if( n == 0)
			return 0;

		C.clear();

		for( int i = 0; i < n; i++ )
		{
			cin>>a[i];
		}
	
		cin>>m;
		for( int i = 0; i < m; i++ )
		{
			cin>>b[i];
		}

		int i = 0, j = 0;
		int suma = 0, sumb = 0, result = 0;
		while (1) {

			if (i < n && j < m && a[i] < b[j]) {
				suma += a[i];
				i++;
			} else if (i < n && j < m && b[j] < a[i]) {
				sumb += b[j];
				j++;
			} else if (i < n && j < m && a[i] == b[j]) {
				result += max(suma + a[i], sumb + b[j]);
				suma = sumb = 0;
				i++;
				j++;
			}

			if ( i >= n && j >= m )
				break;

			if ( i >= n ) {
				while ( j < m ) {
					sumb += b[j];
					j++;
				}
				result += max(suma , sumb);
				break;
			}

			if ( j >= m ) {
				while ( i < n ) {
					suma += a[i];
					i++;
				}
				result += max(suma, sumb);
				break;
			}
		}

		cout << result << endl;


		// long long int i = 0, j = 0;

		// while( i < n && j < m )
		// {
		// 	if( A[i] < B[j] )
		// 		i++;
		// 	else
		// 		if( A[i] > B[j] )
		// 			j++;
		// 		else
		// 		{
		// 			C.push_back(A[i]);
		// 			i++;
		// 			j++;
		// 		}
		// }

		// long long int k = 0; 
		// sum[0] = 0;

		// if( C.size() == 0)
		// {
		// 	for( i = 0; i < n; i++ )
		// 		sum[k] += A[i];

		// 	sum2[0] = 0;

		// 	for( i = 0; i < m; i++ )
		// 		sum2[k] += B[i];

		// 	cout<<max(sum[k],sum2[k])<<endl;
		// 	continue;
		// }
		
		// for( i = 0; i < n; i++ )
		// {
		// 	if( A[i] == C[k] )
		// 	{
		// 		k++;
		// 		sum[k] = A[i];
		// 	}
		// 	else
		// 		sum[k] += A[i];
		// }

		// k = 0; 
		// sum2[0] = 0;
		// for( i = 0; i < m; i++ )
		// {
		// 	if( B[i] == C[k] )
		// 	{
		// 		k++;
		// 		sum2[k] = B[i];
		// 	}
		// 	else
		// 		sum2[k] += B[i];
		// }

		// long long int ans = 0;
		// for( int i = 0; i <= C.size(); i++ )
		// 	ans += max(sum[i],sum2[i]);

		// cout<<ans<<endl;
	}
	return 0;
}