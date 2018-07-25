#include<bits/stdc++.h>
using namespace std;

int *buildTable(int arr[],int n, int *table)
{
	int m = (int)ceil(sqrt(n));
	table = new int[m];
	for(int i=0;i<m;i++)
	{
		if(i == m-1)
		{
			int gcd = arr[i*m];
			for(int j = i*m; j<n;j++)
				gcd = __gcd(gcd,arr[j]);
			table[i] = gcd;
			
		}
		else
		{	int gcd = arr[i*m];
			for(int j=i*m;j<i*m + m;j++)
				gcd = __gcd(gcd,arr[j]);
			table[i] = gcd;
		}
	}

	return table;
}

int query(int l,int r, int *table , int *a , int n)
{
	int num_blocks = (int)ceil(sqrt(n));
	int block_start = l/num_blocks;
	int block_end = r/num_blocks;
	int gcd = a[l];
	for(int i=block_start+1 ; i< block_end ; i++)
		gcd = __gcd(gcd,table[i]);
	for(int i=l; i< (block_start + 1)*num_blocks ; i++)
		gcd = __gcd(gcd,a[i]);
	for(int i = block_end * num_blocks ; i<= r ; i++)
		gcd = __gcd(gcd,a[i]);

	return gcd;
}

int main()
{
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    int *table;
    table = buildTable(a, n , table);
    cout << query(0, 2 , table , a , n) << endl;
    cout << query(1, 3 , table , a , n) << endl;
    cout << query(4, 5 , table , a , n) << endl;
    return 0;
}
