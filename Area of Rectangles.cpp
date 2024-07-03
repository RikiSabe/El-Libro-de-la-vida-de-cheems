#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6;
const int MAXN = 2 * MAXX + 1;

struct Event {
	int t, x, y0, y1;
	// t = 1 for left bound, -1 for right bound
	bool operator<(const Event &e) { return x < e.x; }
};

int N;
vector<Event> E;

// segment tree
pair<long long, long long> tree[MAXN * 4];
int lazy[MAXN * 4];

pair<long long, long long> merge(pair<long long, long long> a,
                                 pair<long long, long long> b) {
	if (a.first < b.first) { return a; }
	if (a.first > b.first) { return b; }
	return {a.first, a.second + b.second};
}

// pushes lazy updates down to children
void pushdown(int t) {
	if (lazy[t]) {
		tree[t << 1].first += lazy[t];
		lazy[t << 1] += lazy[t];
		tree[t << 1 | 1].first += lazy[t];
		lazy[t << 1 | 1] += lazy[t];
		lazy[t] = 0;
	}
}

// constructs the segment tree
void build(int t = 1, int tl = 0, int tr = MAXN) {
	if (tl == tr) {
		tree[t] = {0, 1};
		return;
	}

	int tm = (tl + tr) >> 1;
	build(t << 1, tl, tm);
	build(t << 1 | 1, tm + 1, tr);
	tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
}

// adds v to indices l to r
void update(int l, int r, int v, int t = 1, int tl = 0, int tr = MAXN) {
	if (r < tl || tr < l) { return; }
	if (l <= tl && tr <= r) {
		tree[t].first += v;
		lazy[t] += v;
		return;
	}
	pushdown(t);

	int tm = (tl + tr) >> 1;
	update(l, r, v, t << 1, tl, tm);
	update(l, r, v, t << 1 | 1, tm + 1, tr);
	tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
}

// queries min and count of entire segment tree
long long query() {
	// always maintain one element with value of zero
	// so we don't have to check if zero is the minimum
	return MAXN + 1 - tree[1].second;
}

int main() {
	cin >> N;
	build();
	for (int i = 0; i < N; i++) {
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;

		// make coordinates positive
		x0 += MAXX, y0 += MAXX;
		x1 += MAXX, y1 += MAXX;

		E.push_back({1, x0, y0, y1 - 1});
		E.push_back({-1, x1, y0, y1 - 1});
	}

	sort(E.begin(), E.end());

	long long ans = 0;
	update(E[0].y0, E[0].y1, 1);
	for (int i = 1; i < 2 * N; i++) {
		ans += query() * (E[i].x - E[i - 1].x);
		update(E[i].y0, E[i].y1, E[i].t);
	}
	cout << ans << '\n';
}
