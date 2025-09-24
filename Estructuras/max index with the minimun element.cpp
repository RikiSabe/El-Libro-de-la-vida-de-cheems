	vector<int> leftMin(n), rightMin(n);
    vector<int> leftMax(n), rightMax(n);

    // Monotonic stack for minimum (increasing)
    stack<int> sMin;
    for (int i = 0; i < n; ++i) {
        while (!sMin.empty() && a[sMin.top()] > a[i])
            sMin.pop();
        leftMin[i] = sMin.empty() ? i + 1 : i - sMin.top();
        sMin.push(i);
    }

    while (!sMin.empty()) sMin.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!sMin.empty() && a[sMin.top()] >= a[i])
            sMin.pop();
        rightMin[i] = sMin.empty() ? n - i : sMin.top() - i;
        sMin.push(i);
    }

    // Monotonic stack for maximum (decreasing)
    stack<int> sMax;
    for (int i = 0; i < n; ++i) {
        while (!sMax.empty() && a[sMax.top()] < a[i])
            sMax.pop();
        leftMax[i] = sMax.empty() ? i + 1 : i - sMax.top();
        sMax.push(i);
    }

    while (!sMax.empty()) sMax.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!sMax.empty() && a[sMax.top()] <= a[i])
            sMax.pop();
        rightMax[i] = sMax.empty() ? n - i : sMax.top() - i;
        sMax.push(i);
    }
