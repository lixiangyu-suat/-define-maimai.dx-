/*
 * 目标：求长度为 k 的滑动窗口内的最小值与最大值
 * 时间复杂度：O(n)，每个元素最多进出队列一次
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    deque<int> dq;
    // 1. 求最小值 (维护单调递增队列)
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while (!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << " ";
    }
    cout << endl;

    dq.clear();
    // 2. 求最大值 (维护单调递减队列)
    for (int i = 1; i <= n; i++) {
        if (!dq.empty() && i - dq.front() >= k) dq.pop_front();
        while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << " ";
    }
}

