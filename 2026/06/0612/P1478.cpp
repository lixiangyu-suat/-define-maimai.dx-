#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;

    int h, m;
    int less_n = 0;

    vector<int> apple(n);
    for (int i = 0; i < n; i++){
        cin >> h >> m;
        if (h <= a + b){
            apple[less_n++] = m;
        }
    }
    sort(apple.begin(), apple.begin() + less_n);
    int i = 0;
    for (; i < less_n; i++){
        if (apple[i] > s) break;
        s -= apple[i];
    }
    cout << i;
    return 0;
}