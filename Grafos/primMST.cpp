vector<vector<int>> adj[N];
// Return the total sum of the Minimum Spanning Tree
int prim(int start) {
    int cost = 0;
    vector<int> dis(N, inf), parent(N);
    vector<bool> vis(N);
    set<vector<int>> s;
    dis[start] = 0;
    s.insert({0, start});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1], v = parent[x[1]], w = x[0];
        cost += w;
        for(auto it : adj[x[1]]){
            if( vis[it[0]] ) continue;
            if( dis[it[0]] > it[1] ){
                s.erase({dis[it[0]], it[0]});
                dis[it[0]] = it[1];
                s.insert({dis[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
    return cost;
}
// Should start node inicial = (1 or 0)
