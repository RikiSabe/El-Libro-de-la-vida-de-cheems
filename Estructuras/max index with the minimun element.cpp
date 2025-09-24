	int n; cin >> n;
	vector<ll> A(n); FOR(i, 0, n) cin >> A[i];
	vector<ll> prev(n, 1), nxt(n, n); // hasta donde soy menor a la izq/derecha
	stack<int> ps, ns;
	FOR(i, 0, n) {
		while(ns.size() && A[ns.top()] > A[i]) {
			nxt[ns.top()] = i; ns.pop();
		}
		ns.push(i);
	}
	for(int i = n - 1; i >= 0; i --) {
		while(ps.size() && A[ps.top()] > A[i])  {
			prev[ps.top()] = i + 2;
			ps.pop();
		}
		ps.push(i);
	}
6
2 4 4 9 4 9
? prev: [ 1 , 2 , 2 , 4 , 2 , 6 ]
? nxt: [ 6 , 6 , 6 , 4 , 6 , 6 ]
