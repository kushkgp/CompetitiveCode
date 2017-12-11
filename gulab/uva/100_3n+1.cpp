#include <bits/stdc++.h>
using namespace std;

int cycle_length(int n){
	int x = 1;
	while(n!=1){
		if(n%2==0) n/=2;
		else n = 3*n+1;
		x++;
	}
	return x;
}

int main(){
	int n1,n2;
	string line;
	while(getline(cin,line)){
		sscanf(line.c_str(),"%d %d",&n1,&n2);
		long long int m = 0;
		for (int i = min(n1,n2); i <= max(n1,n2); ++i)
		{
			long long int temp = cycle_length(i);
			if(m<temp)
				m=temp;
		}
		printf("%d %d %lld\n", n1,n2,m);
	}
}