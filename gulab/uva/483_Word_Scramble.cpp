#include <bits/stdc++.h>
#define size 100000

char* stringReverse(char *cstr)
{
	int len = strlen(cstr);
    char swap;

    for (int i = 0; i < len/2; i++)
    {
        swap = cstr[i];
        cstr[i] = cstr[len-i-1];
        cstr[len-i-1] = swap;
    }
    return cstr;
}

int main(){
	char line[size];
	int x = 0;
	char c;
	while(1){
		c = getc(stdin);
		if(c==' '||c=='\t'||c=='\n'||c==EOF){
			line[x]='\0';
			if(x){
				x=0;
				printf("%s",stringReverse(line));
			}
			if(c==EOF)
				break;
			else
				printf("%c",c);
		}
		else
			line[x++] = c;
	}
}