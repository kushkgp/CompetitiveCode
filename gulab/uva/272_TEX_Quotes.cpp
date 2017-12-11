#include <bits/stdc++.h>
#define size 100000
using namespace std;
int main(){
	int f = 1;
	char s[size];
	while(fgets(s,size-1,stdin)){
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
		{
			if(s[i]=='"'){
				if(f)
					printf("``");
				else
					printf("''");
				f=f^1;
			}
			else
				printf("%c",s[i]);
		}
	}
	return 0;
}