vvi Solution::generateMatrix(int n) {
	vvi v;
	v.resize(n,vector<int>(n));
	int ll=0,rl=n-1,ul=0,dl=n-1;
	int dir = 0;
	int x = 1;
	while(ll<=rl&&ul<=dl){
		switch(dir){
			case 0:
				for (int i = ll; i <= rl; ++i)
				{
					v[ul][i] = x++;
				}
				ul++;dir++;
				break;
			case 1:
				for (int i = ul; i <= dl; ++i)
				{
					v[i][rl] = x++;
				}
				rl--;dir++;
				break;
			case 2:
				for (int i = rl; i >= ll; --i)
				{
					v[dl][i] = x++;
				}
				dl--;dir++;
				break;
			case 3:
				for (int i = dl; i >= ul; --i)
				{
					v[i][ll] = x++;
				}
				ll++;dir=0;
				break;
		}
	}
	return v;
}
