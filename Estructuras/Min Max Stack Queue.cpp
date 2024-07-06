#define ii pair<int,int> 
#define iii pair<ii,int> 

struct stack_max_min {
    stack<iii> st;
    int getmin() { return st.top().first.second; }
    int getmax() { return st.top().second; }
    bool empty() { return st.empty(); }
    int size() { return st.size(); }
    void push(int x) {
        int a = x, b = x;
        if (!empty()) {
            a = min(a, getmin());
            b = max(b, getmax());
        }
        st.push({{x, a}, b});
    }
    void pop() {st.pop();}
    int top() { return st.top().first.first; }
    void swap(stack_max_min &x) { st.swap(x.st); }
};
 
// deque max min
struct deque_max_min {
    stack_max_min l, r, t;
    void rebalance() {
        bool f = false;
        if (r.empty()) {f = true; l.swap(r);}
        int sz = r.size() / 2;
        while (sz--) {t.push(r.top()); r.pop();}
        while (!r.empty()) {l.push(r.top()); r.pop();}
        while (!t.empty()) {r.push(t.top()); t.pop();}
        if (f) l.swap(r);
    }
    int getmin() {
        if (l.empty()) return r.getmin();
        if (r.empty()) return l.getmin();
        return min(l.getmin(), r.getmin());
    }
    int getmax() {
        if (l.empty()) return r.getmax();
        if (r.empty()) return l.getmax();
        return max(l.getmax(), r.getmax());
    }
    bool empty() {return l.empty() && r.empty();}
    int size() {return l.size() + r.size();}
    void push_front(int x) {l.push(x);}
    void push_back(int x) {r.push(x);}
    void pop_front() {if (l.empty()) rebalance(); l.pop();}
    void pop_back() {if (r.empty()) rebalance(); r.pop();}
    int front() {if (l.empty()) rebalance(); return l.top();}
    int back() {if (r.empty()) rebalance(); return r.top();}
    void swap(deque_max_min &x) {l.swap(x.l); r.swap(x.r);}
};
