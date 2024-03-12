vector<ii> adj[N];

void path_prim(int n){ // size of graph
    n++;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int start = 1;
    vector<int> key(n, inf), parent(n, -1), inMST(n,0);
    pq.push({0,start});
    key[start] = 0;
    while( !pq.empty() ){
        int u = pq.top().second;
        pq.pop();
        for( auto it : adj[u] ){
            int v = it.first;
            int wt = it.second;

            if( !inMST[v] && key[v] > wt ){
                key[v] = wt;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    FOR(i,start + 1,n){
        cout << parent[i] << " - " << i << endl;
    }
}
