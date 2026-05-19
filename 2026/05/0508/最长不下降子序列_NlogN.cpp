#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int low[N];

int main(){
    //假如序列s里面的元素有负的值，也无需初始化
    int n; cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    int len = 0;
    for (auto c : s){ //s是一个序列
        int id = lower_bound(low, low+len, c) - low; //low是数组第一个下标的地址
        //upper_bound为第一个大于i的下标地址
        low[id] = c;
        if (id == len) len++;
    }
    cout << len << endl;
    return 0;
}