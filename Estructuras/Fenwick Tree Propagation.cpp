ll bit1[N],bit2[N];

void update(ll bit[], int idx, ll val){
    for(int x = idx; x < N; x += x & -x)
        bit[x] += val;
}

ll query(ll bit[], int idx){
    ll ret = 0;
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    return ret;
}

FOR(i, 0, n) {
    cin >> v >> l >> r ; // value and indexes to add a value
    update(bit1,l,v); update(bit1,r + 1,-v);
    update(bit2,l,-(long long)v * (l - 1)); update(bit2,r + 1,(long long)v * r);
}

// query for [l, r]
FOR(i , 1, s.size() + 1) {
	cin >> l >> r;
    ll val = (query(bit1, r) * r + query(bit2,r) - query(bit1,l - 1) * (l - 1) - query(bit2,l - 1));
}