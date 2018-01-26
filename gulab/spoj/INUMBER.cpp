#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define Int long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair
 
 
// storing the last digit we added
int dp[1011][1011] ;
//dp[i][j] stores previous sum  where i == modulo and j ==digit_sum 
 
int lst[1011][1011] ;
// stores the last number , needed for backtracking once we find // the ans
 
int MO[1011][1011];
 // stores the last modulo , needed for backtracking 
 
int main ( )
 {
 
  
   int t ;
   cin >>  t ;
 
 
 
  while(t--)
    {
 
         int n;
         cin >> n;
            FOR(i, 1011 )
             FOR(j, 1011 )
               { dp[i][j] = - 1 ; // Initializing 
                  MO[i][j] = 0 ; }
 
 
 
         queue<pair<int,int > >q ; 
 
// queue to perform bfs to get the smallest number
 
         for( int i = 1  ; i  <= 9 ; i ++ )
              { q.push( mp ( i%n , i )) ;
                dp[ i%n ][ i ]  = i;   //  storing the digit sum
                lst[i%n][ i ] = i ; }  // storing the last element 
 
 // Note -:  initial insertion starts from 1 and not 0 --> no 
 // leading zeroes !
 
          while(  !q.empty( ) )
           {
               int ds , rem ;
               pair<int,int> tp  =  q.front();                
          //   taking a temporary pair
               q.pop();
               rem  = tp.ff ; 
         // remainder of current state
               ds   = tp.ss ;   
         //  digit sum of current sum
 
               if( rem == 0 && ds == n)  // required condition
                     break;
 
// running through all  possible states
      for( int i = 0 ; i <= 9 ; i ++ )   
                 {
                    tp.ff  =  (rem*10 + i )%n ;    // new remainder
                    tp.ss  =   ds + i ;           //  new digit sum
 
  // checking whether if we have covered/visited this state before       
  //and whether this new state is possible or not
          if(  dp[tp.ff][tp.ss] != -1 ||  tp.ss > n  ) 
                        continue;
                      q.push( tp );  
    //  if we have not covered this state then cover this state
          dp[tp.ff][tp.ss]  = ds  +  i;  //  storing the digit sum
          lst[tp.ff][tp.ss] = i ;     // storing the last number 
          MO[tp.ff][tp.ss] = rem;     //  storing the modulo
 
                 }
 
 
 
           }
 /**************** BACKTRACKING ********************/
           int m = 0 ,s = n ;
           stack<int>ans;
           for( int i = 0 ; ; i ++ )
            {
              if( m==0 && s== 0 )break;
              ans.push(lst[m][s]) ;    
              int m1 =   MO[m][s]  ;
          
              int s1 =  (dp[m][s]  - lst[m][s])  ;
              m = m1 ; s = s1 ;
            }
 
          while( !ans.empty()){  cout<< ans.top(); ans.pop();}
                    cout<<endl;
          
 
 
 
    }
 
 
 
 
 }
647 Vi