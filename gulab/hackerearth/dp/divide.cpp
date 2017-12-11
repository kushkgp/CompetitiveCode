#include <bits/stdc++.h>
#define bs 1000000007
using namespace std;
long long pw(long long a,long long b)
{
 a%=bs;
 if (b==0)
  return 1;
 if (b%2)
  return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}
unordered_set<long long> was;
unordered_map<long long, long long> memo;
vector<long long> get_divs(long long x)
{
 vector<long long> divs;
 for (long long i=1;i*i<=x;i++)
 {
  if (x%i)
   continue;
  divs.push_back(i);
  if (i!=1&&x/i!=i)
   divs.push_back(x/i);
 }
 return divs;
}
long long solve(long long x)
{
 if (x<=2)
  return 1;
 if (was.find(x)!=was.end())
  return memo[x];
 was.insert(x);
 vector<long long> divs=get_divs(x-1);
 long long res=0;
 for (int i=0;i<divs.size();i++)
 {
  long long Q=solve(divs[i]);
  res+=pw(Q,((x-1)/divs[i]));
  res%=bs;
 }
 memo[x]=res;
 return res;
}
int main(){
long long n;
cin>>n;
cout<<solve(n)<<endl;
return 0;}