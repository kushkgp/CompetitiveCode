/* first computes the neares smaller neighbour in both directions and then computes area from it */

ll ans(const vi & v, int n){
	int left[n],right[n];
	left[0] = -1;
	stack<pii> s;
	s.push(mp(v[0],0));
	for (int i = 1; i < n; ++i)
	{
		while(!s.empty()&&s.top().ff>=v[i]){
			s.pop();
		}
		if(s.empty())
			left[i] = -1;
		else
			left[i] = s.top().ss;
		s.push(mp(v[i],i));
	}
	while(!s.empty()){
		s.pop();
	}
	right[n-1] = n;
	s.push(mp(v[n-1],n-1));
	for (int i = n-2; i >= 0; --i)
	{
		while(!s.empty()&&s.top().ff>=v[i]){
			s.pop();
		}
		if(s.empty())
			right[i] = n;
		else
			right[i] = s.top().ss;
		s.push(mp(v[i],i));
	}
	ll result = 0;
	for (int i = 0; i < n; ++i)
	{
		result = max(result,(ll)v[i]*(right[i] - left[i]-1));
	}
	return result;
}