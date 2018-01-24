
typedef vector<vector<ll> > matrix;

matrix mul(matrix & a, matrix & b){
	assert(a[0].size()==b.size());
	matrix c(a.size(),vector<ll>(b[0].size(),0));
	FOR(i,a.size()) FOR(j,b[0].size()) FOR(k,b.size()){
		c[i][j] += (a[i][k]*b[k][j]);
		c[i][j]%=MOD;
	}
	return c;
}

void print(matrix & a){
	FOR(i,a.size()){
		FOR(j,a[0].size()){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}