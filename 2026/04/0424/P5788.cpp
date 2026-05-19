#include <bits/stdc++.h>
using namespace std;

vector<int> a, lst_time;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n;
    a.resize(n+1); lst_time.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<int> stk; //存储下标
    for (int i = 1; i <= n; i++){
        while (stk.empty() == false && a[stk.top()] < a[i]) {//维护严格单调递增
            lst_time[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for (int i = 1; i <= n; i++) cout << lst_time[i] << ' ';
    return 0;
}