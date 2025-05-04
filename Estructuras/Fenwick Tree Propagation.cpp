ll bit1[N], bit2[N];

void propagate(ll bit[], int idx, ll val){
    for(int x = idx; x < N; x += x & -x)
        bit[x] += val;
}

ll qry(ll bit[], int idx){
    ll ret = 0;
    for(int x = idx; x > 0;x -= x & -x)
        ret += bit[x];
    return ret;
}


ll qry(ll l, ll r) { // check sum [l, r]
	l ++; r ++;
	return (qry(bit1, r) * r + qry(bit2,r) - qry(bit1,l - 1) * (l - 1) - qry(bit2,l - 1));
}

void propagate(ll l, ll r, ll v) { // propagate +v between [l, r]
	l ++; r ++;
	propagate(bit1, l, v); propagate(bit1, r + 1, -v);
        propagate(bit2, l, -(ll)v * (l - 1)); 
	propagate(bit2, r + 1, (ll)v * r);
}

// TODO: Should we use struct????
