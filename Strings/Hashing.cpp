ll pot(ll b, ll e , ll m) {
    ll res = 1;
    while (e > 0) {
        if (e&1) res = res * b % m;
        e >>= 1;
        b = b * b % m;
    }
    return res;
}
 
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
// also for ll exists mt19937_64
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
 
struct Hash {
	int p = randint(30, 1e6), m[2], in[2];
	vector<int> h[2], inv[2];
	Hash(string s)
	{
		m[0] = 998244353, m[1] = 1000000009;
		for(int i = 0; i < 2; i++)
		{
			in[i] = pot(p, m[i]-2, m[i]);
			h[i].resize(s.size() + 1);
			inv[i].resize(s.size() + 1);
			ll acu = 1;
			h[i][0] = 0, inv[i][0] = 1;
			for(int j = 0; j < s.size(); j++)
			{
				h[i][j + 1] = (h[i][j] + acu * s[j]) % m[i];
				inv[i][j + 1] = (1ll * inv[i][j] * in[i]) % m[i];
				acu = (acu * p) % m[i];
			}
		}
	}
	
	// Return the hash of the the substring of 's' from index 'b' to 'e' inclusive.
	// Note that ABCABC, the hash of 0 to 2 is the same as 3 to 5. 
	ll get(int b, int e)
	{
                e++; // Important to make this inclusive
		ll ha[2];
		for(int i = 0; i < 2; i++)
			ha[i] = ((((h[i][e] - h[i][b]) * (ll)inv[i][b]) % m[i]) + m[i]) % m[i];
		return((ha[0] << 32) | ha[1]) ;
	}
};
