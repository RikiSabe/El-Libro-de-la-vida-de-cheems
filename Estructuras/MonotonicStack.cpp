
vector<ll> getPrevMin(int n, vector<ll> A) {
    vector<ll> prev(n, 0);
  	stack<int> ps;
      for(int i = n - 1; i >= 0; i --) {
  		while(ps.size() && A[ps.top()] > A[i])  {
  			prev[ps.top()] = i + 1;
  			ps.pop();
  		}
  		ps.push(i);
  	}
    return prev;
}

vector<ll> getNxtMin(int n, vector<ll> A) {
    vector<ll> nxt(n, n + 1);
  	stack<int> ns;
      FOR(i, 0, n) {
  		while(ns.size() && A[ns.top()] > A[i]) {
  			nxt[ns.top()] = i + 1; ns.pop();
  		}
  		ns.push(i);
  	}
    return nxt;
}

vector<ll> getPrevMax(int n, vector<ll> A) {
    vector<ll> prev(n, 0);
  	stack<int> ps;
      for(int i = n - 1; i >= 0; i --) {
  		while(ps.size() && A[ps.top()] < A[i])  {
  			prev[ps.top()] = i + 1;
  			ps.pop();
  		}
  		ps.push(i);
  	}
    return prev;
}

vector<ll> getNxtMax(int n, vector<ll> A) {
    vector<ll> nxt(n, n + 1); 
    stack<int> ns;
      FOR(i, 0, n) {
      while(ns.size() && A[ns.top()] < A[i]) {
        nxt[ns.top()] = i + 1; ns.pop();
      }
      ns.push(i);
    }
    return nxt;
}


void cumbia420PaLosCheems(int testCase) {
    int n; cin >> n;
	  vector<ll> A(n); FOR(i, 0, n) cin >> A[i];
}
