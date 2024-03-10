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
