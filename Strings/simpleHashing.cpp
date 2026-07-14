struct StringHash {
    static const long long MOD = 1000000007;
    static const long long BASE = 911382323; // cualquier número aleatorio < MOD

    vector<long long> h, p;

    StringHash(const string &s) {
        int n = s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * BASE + s[i]) % MOD;
            p[i + 1] = (p[i] * BASE) % MOD;
        }
    }

    // hash de s[l...r] (0-indexado, inclusivo)
    long long get(int l, int r) {
        long long res = h[r + 1] - h[l] * p[r - l + 1] % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

// USO

string s = "abracadabra";

StringHash H(s);

cout << H.get(0, 2) << "\n";   // hash de "abr"
cout << H.get(3, 5) << "\n";   // hash de "aca"

if (H.get(0,2) == H.get(7,9))
    cout << "Iguales\n";
