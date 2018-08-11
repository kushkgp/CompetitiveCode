#include <bits/stdc++.h>

using namespace std;

int hire, sal, sev, req[25], dp[30][100], n;

int recur( int month, int workers )
{
	if( month == n )
	{
		if( workers >= req[month-1] )
			return min(sev,sal)*(workers - req[month-1]) + sal*req[month-1];
		else
			return hire*(req[month-1] - workers) + sal*req[month-1];
	}
	
	if( dp[month][workers] != -1 )
		return dp[month][workers];

	int cost = 0, newworkers = 0;
	
	if( workers < req[month-1] )
	{
		cost += hire*(req[month-1] - workers );
		newworkers = req[month-1];
	}
	else
	{
		newworkers = workers;
	}

	int ans = 0, mini = INT_MAX;

	for( int i = month + 1; i <= n; i++ )
	{
		mini = min(mini, req[i-1]);
	}

	if( mini > 0 && newworkers > mini )
	{
		ans = INT_MAX;
		for( int i = newworkers; i >= mini; i-- )
		{
			ans = min(ans, (newworkers - i)*sev + recur(month+1, i));
		}
	}
	else
		if( newworkers <= mini )
			ans = recur(month + 1, newworkers);

	// cout<<ans<<" "<<month<<" "<<cost<<" "<<newworkers*sal<<" "<<mini<<endl;
	return dp[month][workers] = ans + cost + newworkers*sal;
}

int main()
{
	int count = 1;
	while(1)
	{
		cin>>n;
		if( n == 0 )
			return 0;
		cin>>hire>>sal>>sev;
		
		memset(dp, -1, sizeof(dp));
		for( int i = 0; i < n; i++ )
			cin>>req[i];

		 printf("Case %d, cost = $%d\n",count++, recur(1,0));
	}	

}