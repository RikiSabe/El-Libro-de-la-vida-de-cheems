bitset<N> marked;
vector<int> primis;

vector<ii> Factor(int x) {
	vector<ii> factor;
	for(int i = 0; primis[i] * primis[i] <= x; i ++) {
		if(x % primis[i] == 0) {
			int c = 0;
			while(x % primis[i] == 0) {
				x /= primis[i]; c ++;
			}
			factor.pb(ii(primis[i], c));
		}
	}
	if(x != 1) factor.pb(ii(x, 1));
	return factor;
}

void init() {
	
  marked[0] = marked[1] = 1;
	FOR(i, 2, N) {
		if(!marked[i]) {
			for(int j = i + i; j < N; j += i) {
				marked[j] = 1;
			}
		}
	}

	FOR(i, 2, N) if(!marked[i]) primis.pb(i);
  
	debugList(primis);
}
