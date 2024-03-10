int G[N][N];
int in[N], out[N];
bitset<N> visited;

void dfs(int node) {
	visited[node] = 0;
	FOR(i, 1, 27) {
		if(G[node][i] && visited[i]) {
			dfs(i);
		}
	}
}

bool checkEulerPath(int node) {
	dfs(node);
	int cntIn = 0, cntOut = 0;
	FOR(i, 1, 27) {
		if(visited[i]) { // no se pude llegar
			return 0;
		}
		if(in[i] != out[i]) { 
			if(in[i] - out[i] == 1) cntIn ++;
			else if(out[i] - in[i] == 1) cntOut ++;
			else { return 0; }
		}
	}
	return ( (cntIn == 1 && cntOut == 1) || (cntIn == 0 && cntOut == 0));
}

void clear() {
	visited.reset();
	FOR(i, 0, N) {
		in[i] = 0, out[i] = 0;
		FOR(j, 0, N) G[i][j] = 0;	
	}
}

int main(){ // Example 
    int n; cin >> n;
	clear();
	string s;
	int last = -1;
	FOR(i, 0, n) {
		cin >> s;
		int u = s[0] - 'a' + 1, v = s[s.size() - 1] - 'a' + 1;
		G[u][v] ++; G[v][u] ++;
		out[u] ++; in[v] ++;
		visited[u] = 1; visited[v] = 1; last = u;
	}
    assert(last != -1);
    cout << (checkEulerPath(last)? "YES" : "NO" ) << endl;
}
