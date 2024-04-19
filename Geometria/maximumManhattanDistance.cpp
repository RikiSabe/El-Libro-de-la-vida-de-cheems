ll maximumManhattanDistance(vector<ii>& P, int n) {
	vector<ll> V1(n), V2(n);
    for (int i = 0; i < n; i++) {
        V1[i] = P[i].first + P[i].second;
        V2[i] = P[i].first - P[i].second;
    }
    sort(all(V1));
    sort(all(V2));
 
    ll mx = max(V1.back() - V1.front(), V2.back() - V2.front());
	return mx;
}
