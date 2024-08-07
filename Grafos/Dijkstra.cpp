vector<ll> Dijkstra(int a, int n) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, a));
    vector<ll> dist(n + 1, infL);
    dist[a] = 0;
 
    while(!pq.empty()) {
        ii U = pq.top(); pq.pop();
        ll w = U.first, u = U.second;
	if(dist[u] < w) {
		continue;
	}
        for(ii adj : G[u]) {
            ll v = adj.first, new_w = adj.second;
			if(w + new_w < dist[v]) {
				dist[v] = w + new_w;
				pq.push(ii(dist[v], v));
			}
        }
    }
    debugList(dist);
    return dist;
}
