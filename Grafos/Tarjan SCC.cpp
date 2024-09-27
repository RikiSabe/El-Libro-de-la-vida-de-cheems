vi adj[N], adj_new[N];
int dfs_num[N], dfs_low[N], vis[N] = {0}, gr[N], out[N];
int dfs_v = 0, group = 0;
stack<int> st;

void Tarjan(int node){
	vis[node] = 1;
	st.push(node);
	dfs_low[node] = dfs_num[node] = dfs_v++;
	for( auto u : adj[node] ){
		if( vis[u] == 0 ){
			Tarjan(u);
			dfs_low[node] = min(dfs_low[node], dfs_low[u]);
		}else if( vis[u] == 1 ){
			dfs_low[node] = min(dfs_low[node], dfs_low[u]);
		}
	}
	if( dfs_num[node] == dfs_low[node] ){
		group++;
		while( vis[node] == 1 ){
			int v = st.top();
			st.pop();
			gr[v] = group;
			vis[v] = 2;
			if( v == node ) break;
		}
	}
}

vi adj[N], adj_new[N];
int dfs_num[N], dfs_low[N], vis[N] = {0}, gr[N], out[N];
int dfs_v = 0, group = 0;
stack<int> st;

void tarjan(int node){
	vis[node] = 1;
	st.push(node);
	dfs_low[node] = dfs_num[node] = dfs_v++;
	for( auto u : adj[node] ){
		if( vis[u] == 0 ){
			tarjan(u);
			dfs_low[node] = min(dfs_low[node], dfs_low[u]);
		}else if( vis[u] == 1 ){
			dfs_low[node] = min(dfs_low[node], dfs_low[u]);
		}
	}
	if( dfs_num[node] == dfs_low[node] ){
		group++;
		while( vis[node] == 1 ){
			int v = st.top();
			st.pop();
			gr[v] = group;
			vis[v] = 2;
			if( v == node ) break;
		}
	}
}

void solve(int ith){
	int n, m;
	cin >> n >> m;
	FOR(i,0,m){
		int a,b;
		cin >> b >> a;
		adj[a].push_back(b);
	}
	FOR(i,1,n + 1){
		if( vis[i] == 0 ) tarjan(i);
	}
	FOR(i,1,n + 1){
		for( auto j : adj[i] ){
			if( gr[i] == gr[j] ) continue;
			out[ gr[i] ] = 1;
		}
	}
	int ans = 0;
	FOR(i,1,group + 1){
		if(out[i] == 0) ans ++;
	}
	cout << ans << nl;
}
