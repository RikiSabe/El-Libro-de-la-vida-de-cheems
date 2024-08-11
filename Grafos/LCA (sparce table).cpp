const int LOG2 = 20;
int up[N][LOG2];
vector<ii> Tree[N];

ll depth[N];
ll S[N];

void dfs(int u, int p, int d, ll sum){
	depth[u] = d;
	S[u] = sum;

	up[u][0] = p;
	for(int i = 1; i < LOG2; i ++){
		up[u][i] = up[ up[u][i-1] ] [i-1] ;
	}
	for(ii adj : Tree[u]) {
		int v = adj.first;
		if(v !=p ){
			dfs(v, u, d + 1, sum + adj.second);
		}
	}
}

int lca(int a,int b){
	if(depth[a] < depth[b]){
		swap(a,b);
	}
	int d = depth[a] - depth[b] ;
	for(int i = 0; i < LOG2; i++){
		if( d>>i & 1){
			a = up[a][i];
		}
	}

	if(a == b) return a;
	for(int i = LOG2 - 1; i >= 0; i --){
		if(up[a][i] != up [b][i]){
			a  = up[a][i];
			b  = up[b][i];
		}
	}
	return up[a][0];
}

ll getDis(int u, int v) {
	return S[u] + S[v] - 2 * S[lca(u, v)];
} 

void solve(int testCase) {
	int n; cin >> n;
	int u, v, w;
	FOR(i, 0, n - 1) {
		cin >> u >> v >> w;
		Tree[u].pb({v, w});
		Tree[v].pb({u, w});
	}
	dfs(1, 0, 0, 0);
}
