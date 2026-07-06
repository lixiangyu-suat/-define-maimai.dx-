#include <bits/stdc++.h>
using namespace std;

double sum = 1.0e9;
double dis(double x0, double y0, double x1, double y1){
    return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

void dfs(vector<double>& x, vector<double>& y, vector<int>& id, int step, int n){
    if (step == n+1){
        double d = 0;
        for (int i = 1; i <= n; i++){
            int u = id[i];
            int v = id.at(i-1);
            d += dis(x[u], y[u], x[v], y[v]);
        }
        sum = min(d, sum);
    }

    for (int i = step; i <= n; i++){
        int &t1 = id[i-1], &t2 = id[i], &t3 = id[i+1];
        double d1 = dis(x[t1], y[t1], x[t2], y[t2]) + dis(x[t2], y[t2], x[t3], y[t3]);
        swap(id[i], id[step]);
        double d2 = dis(x[t1], y[t1], x[t2], y[t2]) + dis(x[t2], y[t2], x[t3], y[t3]);
        
        if (d2 <= d1) dfs(x, y, id, step+1, n);
        swap(id[i], id[step]);
    }
    
}
int main(){
    int n;
    cin >> n;

    vector<double> x(n+1), y(n+1);
    vector<int> id(n+1);

    for (int i = 1; i <= n; i++) id[i] = i;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    dfs(x, y, id, 1, n);
    printf("%.2f", sum);
    return 0;
}