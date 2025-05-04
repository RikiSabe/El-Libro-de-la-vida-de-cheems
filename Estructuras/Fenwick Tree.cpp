
struct FenwickTree {
    
    int sz;
    vector<ll> FT;
    
    FenwickTree(int n) {
        n += 10;
        this->sz = n;
        FT.assign(sz, 0);
    }

    void upd(int pos, ll v) {
        pos ++;
        while(pos < sz) { FT[pos] += v; pos += (pos & -pos); }
    }
 
    ll qry(int pos) {
        pos ++;
        ll ans = 0;
        while(pos > 0) { ans += FT[pos]; pos -= (pos & -pos); }
        return ans;
    }

    ll qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }

	void setVal(int pos, ll v) {
		pos ++;
		upd(pos, -(qry(pos) - qry(pos - 1))); upd(pos, v);
	}

	int lower_find(int val) { 
		int idx = 0;
		for(int i = 31 - __builtin_clz(sz); i >= 0; --i) {
			int nidx = idx | (1 << i);
			if(nidx <= sz && FT[nidx] <= val) { /// change <= to <
				val -= FT[nidx];
				idx = nidx;
			}
		}
		return idx;
	}
};
