
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> item(2, vector<int>(10005));//泛化物品
vector<int> v(10005+1), w(10005+1), d(10005+1);

int q[10005], head, tail;

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, C;
    cin >> n >> m >> C;
    item[0].resize(C+1); item[1].resize(C+1);

    for (int i = 1; i <= n; i++){
        cin >> v[i] >> w[i] >> d[i];
    }
//多重背包处理
    vector<int>& dp_old = item[0];
    vector<int> dp_now(C+1);
    for (int i = 1; i <= n; i++){
        //vi * x + y <= C ;体积为v，价值为w，数量为d
        for (int y = 0; y < v[i]; y++){
            head = 1, tail = 0;
            for (int x = 0; x * v[i] + y <= C; x++){
                while (tail >= head && q[head] < x - d[i]) head++; //弹出不在范围内的元素（维护每一个大小为d[i]的区间的最值）
                //倍数x可能很大（最大为背包容量C / w[i])，但是每种物品可能就两三个，因此等价于在某一个背包容量附近找合适的情况（选1-d[i]个物品为最优），余数y负责调和，保证连续，每一个连续的整数都能被遍历到
                while (tail >= head && dp_old[q[tail] * v[i] + y] - q[tail] * w[i] < dp_old[x * v[i] + y] - x * w[i]) tail--;
                q[++tail] = x;
                dp_now[x*v[i] + y] = dp_old[q[head]*v[i] + y] + (x - q[head])*w[i];
            }
        }
        dp_old = dp_now;
    }

    vector<int> ans(C+1), oldans = item[0];
    for (int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;

//泛化物品叠加
        vector<int>& it = item[1];
        for (int j = 0; j <= C; j++){
            it[j] = a*j*j + b*j + c;
            ans[j] = oldans[j];//假设不选第item[1]件物品，则直接继承
        }

        for (int ci = 0; ci <= C; ci++){
            for (int k = 0; k <= ci; k++){
                if (ans[ci] < oldans[k] + item[1][ci-k]) ans[ci] = oldans[k] + item[1][ci-k];
            }
        }
        swap(ans, oldans);
    }
    cout << oldans[C];
    return 0;
}