int sign(ll x) {
    return x == 0 ? 0 : (x > 0 ? 1 : -1);
}

struct Pt {
    ll x, y;
    Pt (ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    ll operator * (const Pt &o) {
        return x * o.x + y * o.y;
    }
    ll operator ^ (const Pt &o) {
        return x * o.y - y * o.x;
    }
    Pt operator + (const Pt &o) {
        return Pt(x + o.x, y + o.y);
    }
    Pt operator - (const Pt &o) {
        return Pt(x - o.x, y - o.y);
    }
    bool operator < (const Pt &o) const {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
};

int orientation(Pt o, Pt a, Pt b){
    return sign((o - a) ^ (o -b));
}

vector <Pt> ConvexHull(vector <Pt> pt) {
    int n = p.size();
    sort(all(pt), [&](Pt a, Pt b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });
    vector <Pt> ans = {pt[0]};
    for (int t : {0, 1}) {
        int m = ans.size();
        for (int i = 1; i < n; ++i) {
            while ( ans.size() > m && orientation(ans[ans.size() - 2], ans.back(), pt[i]) < 0) {
                ans.pop_back();
            }
            ans.push_back(pt[i]);
        }
        reverse(all(pt));
    }
    ans.pop_back();
    return ans;
}