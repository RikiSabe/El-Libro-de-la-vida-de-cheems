// Nearest j < i con A[j] > A[i]
vector<int> prevGreater(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] <= A[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

// Nearest j < i con A[j] >= A[i]
vector<int> prevGreaterEqual(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] < A[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

// Nearest j < i con A[j] < A[i]
vector<int> prevSmaller(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] >= A[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

// Nearest j < i con A[j] <= A[i]
vector<int> prevSmallerEqual(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && A[st.top()] > A[i]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}



// Nearest j > i con A[j] > A[i]
vector<int> nextGreater(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] <= A[i]) st.pop();
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

// Nearest j > i con A[j] >= A[i]
vector<int> nextGreaterEqual(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] < A[i]) st.pop();
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

// Nearest j > i con A[j] < A[i]
vector<int> nextSmaller(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] >= A[i]) st.pop();
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

// Nearest j > i con A[j] <= A[i]
vector<int> nextSmallerEqual(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] > A[i]) st.pop();
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}
