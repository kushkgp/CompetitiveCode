#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;

void printmatrix(int **m,int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void floydwarshall(int **m,int n){
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int x = m[i][k]+m[k][j];
				if (m[i][j]>x)
				{
					m[i][j]=x;
				}
			}
		}
	}
	printmatrix(m,n);
}

int main()
{
	int n;
	cin>>n;
	int **m;
	m=(int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; ++i)
		{
			m[i]=(int*)malloc(n*sizeof(int));
			for (int j = 0; j < n; ++j)
			{
				cin>>m[i][j];
			}
		}
	floydwarshall(m,n);
	return 0;
}