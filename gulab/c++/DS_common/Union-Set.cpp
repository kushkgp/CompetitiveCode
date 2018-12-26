int find_s(vector<int> &p, int x){
	while(x!=p[x]){
		p[x] = p[p[x]];
		x = p[x];
	}
	return x;
}

void union_s(vector<int> & p, int x, int y){
	p[find_s(p, x)] = find_s(p, y);
}