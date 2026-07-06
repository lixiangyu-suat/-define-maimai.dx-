#include <bits/stdc++.h>
using namespace std;

pair<int, double> greedy(vector<double>& p, int l, int r, double x, double oil){
    double minx = 1.0e8;
    int mini = 0;
    for (int i = l; i <= r; i++){
        if (x >= p[i]) return {i, 0.0}; //包括终点站
        if (minx > p[i]){
            minx = p[i];
            mini = i;
        }
    }
    return {mini, -1};//加满油；
}

int main(){
    double S, C, L, p0;
    int N;
    cin >> S >> C >> L >> p0 >> N;
    vector<double> p(N+2);
    vector<double> d(N+2);
    double horizon = C * L;
    d[N+1] = S;
    p[0] = p0;

    for (int i = 1; i <= N; i++){
        cin >> d[i] >> p[i];
    }

    double sum = 0.0;

    double oil = 0.0;
    int idx = 0;

    int newidx;
    int flag = 0;
    while (idx <= N){
        int nxt = idx;
        while (nxt+1 <= N+1 && d[nxt+1]-d[idx] - horizon <= 1e-6) nxt++;
        if (nxt == idx){
            break;
        }
        else{
            double minx = 1.0e8;
            int l = idx + 1, r = nxt;

            flag = 1;

            for (int i = l; i <= r; i++){
                if (p[idx] >= p[i]) {
                    flag = 0; //让油用完
                    newidx = i;
                    break;
                }
                if (minx > p[i]){
                    minx = p[i];
                    newidx = i;
                }
            }
            if (flag == 1){
                double need = C-oil;
                sum += need*p[idx];
                oil = C-(d[newidx] - d[idx])/L;
            }
            else{
                double need = (d[newidx] - d[idx])/L - oil;
                sum += need*p[idx];
                oil = 0;
            }

            idx = newidx;
        }
    }

    if (idx == N+1){
        printf("%.2f", sum);
    }
    else{
        cout << "No Solution";
    }

    return 0;
}