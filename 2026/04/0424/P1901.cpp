#include <bits/stdc++.h>
using namespace std;

int h[100005], v[100005];
vector<int> sum;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n; cin >> n;
    sum.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> h[i] >> v[i];
    stack<int> stk1, stk2;
    for (int i = 1; i <= n; i++){
        while (stk1.empty() == false && h[stk1.top()] < h[i]){
            sum[i] += v[stk1.top()];
            stk1.pop();
        }
        stk1.push(i);
    }
    for (int i = n; i >= 1; i--){
        while (stk2.empty() == false && h[stk2.top()] < h[i]){
            sum[i] += v[stk2.top()];
            stk2.pop();
        }
        stk2.push(i);
    }
    cout << (*max_element(sum.begin()+1, sum.end()));
    return 0;
}