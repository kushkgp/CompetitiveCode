/*
	Author	:	Gulab Arora
	Institue:	IIT Kharagpur
*/

#include <bits/stdc++.h>
#define max3(a,b,c) (max(max(a,b),c))
#define min3(a,b,c) (min(min(a,b),c))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define allr(c) (c).rbegin(),(c).rend()
#define asort(c) sort(all(c))
#define dsort(c) sort(allr(c))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define BOOPT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef vector<pii> vpii;

/* Booth's algorithm : Basically it changes the prefix function of the KMP algo */
int lowest_string_rotation(string & P){
	P+=P;
	vi f(P.length(),-1);
	int s = 0;									/* denotes starting index of lexicographically smallest string */
	for (int i = 1; i < P.size(); ++i)
	{
		char sj = P[i];
		int k = f[i-s-1];						/* k denotes the offset from s to check with i */
		while (k!=-1 && sj != P[s+k+1]){
			/* change k, change s only if lexicographically smaller */
			if(sj < P[s+k+1])					/* this part is extra compared to KMP */
				s = i-k-1;
			k = f[k];
		}
		if (sj != P[s+k+1]){
			if (sj < P[s])						/* this part is extra compared to KMP */
				s = i;
			f[i-s] = -1;
		}
		else
			f[i-s] = k+1;
	}
	return s;
}


int main(){
	string P;
	cin>>P;
	cout<<lowest_string_rotation(P)<<endl;
	return 0;
}