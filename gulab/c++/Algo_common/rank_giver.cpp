/* Changes the array to corresponding ranks */
/* Outputs the max rank given */
int give_ranks(vi & v, int n){
	vpii p;
	for (int i = 0; i < n; ++i)
		p.pb(mp(v[i],i));
	asort(p);
	int j = 1;
	for (int i = 0; i < n; ++i)
	{
		if(i&&p[i].ff!=p[i-1].ff)
			j++;
		v[p[i].ss] = j;
	}
	return j;
}