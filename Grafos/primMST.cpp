vector<ii> adj[N];

int primMST(int start, int n) { // start = 1 hasta n
    int cost = 0;
    vector<int> dis(N, inf), parent(N);
    vector<bool> vis(N);
    set<vector<int>> s;
    dis[start] = 0;
    s.insert({0, start});
    //int band = -1; // control para ver si se puede contruir todos los nodos
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1], w = x[0];
        cost += w;
        //band++;
        for(auto it : adj[x[1]]){
            if( vis[it.first] ) continue;
            if( dis[it.first] > it.second ){
                s.erase({dis[it.first], it.first});
                dis[it.first] = it.second; 
                s.insert({dis[it.first], it.first});
                parent[it.first] = x[1];
            }
        }
    }
    //return (band == n - 1)? cost : -1;
    return cost;
}
