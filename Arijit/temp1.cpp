#include <cstdio>

using namespace std;

char s[1000001];
int L,F[1000000];

int main(){
    int T;
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d %s",&L,s);
        
        printf("Test case #%d\n",tc);
        
        F[0] = 0;

        for( int i = 1; i < L; i++ )
        {
            int j = F[i-1];

            while( j > 0 && s[i] != s[j] )
                j = F[j-1];

            if( s[i] == s[j] )
                j++;

            F[i] = j;
        }
        
        for( int i = 1; i < L; i++ )
        { 
            if(F[i]>0 && (i+1)%(i+1-F[i])==0)
                printf("%d %d\n",i+1,(i+1)/(i+1-F[i]));
        }
        
        puts("");
    }
    
    return 0;
}