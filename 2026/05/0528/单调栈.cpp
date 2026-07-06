/*
 * 目标：寻找数组 a 中每个元素右侧第一个更大值的下标
 * 逻辑：遍历数组，若当前值 > 栈顶值，说明找到了栈顶元素的“右侧最大”，弹出并记录。
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> a, lst_time; // a:原数组, lst_time:存储结果下标

int main() {
    int n; cin >> n;
    a.resize(n + 1); lst_time.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<int> stk; 
    for (int i = 1; i <= n; i++) {
        // 当栈不为空且当前元素大于栈顶元素时
        while (!stk.empty() && a[stk.top()] < a[i]) {
            lst_time[stk.top()] = i; // 记录结果
            stk.pop();               // 弹出已找到结果的下标
        }
        stk.push(i); // 当前下标入栈
    }

    for (int i = 1; i <= n; i++) cout << lst_time[i] << ' ';
    return 0;
}

