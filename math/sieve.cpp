bitset<N> marked;
vector<int> primis;

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
