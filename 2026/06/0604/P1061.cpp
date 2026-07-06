#include <bits/stdc++.h>
using namespace std;

bool catched = false;
int s, t, w;
int len;
int times = 5;
string num;
vector<bool> used;

void print(){
    for (int i = 0; i < len; i++){
        if (used[i]){
            cout << (char)('a'+s+i-1);
        }
    }
    cout << endl;
}
void dfs(int n, int i){ //i : 上一层的指向; n: step(索引)
    int st = i+1; //这一层st从i+1开始找起
    if (!catched){
        if (n == w){
            catched = true;
            return;
        }else{
            st = num[n]-('a'+s-1);
        }
    }
    else {
        if (n == w && times){
            times--;
            print();
        }else if (times == 0){
            return;
        }
    }

    for (int j = st; j < len; j++){
        if (times == 0){
            return;
        }
        if (used[j] == false){
            used[j] = true;
            dfs(n+1, j);
            used[j] = false;
        }
    }
}
int main(){
    cin >> s >> t >> w;
    cin >> num;

    len = t-s+1;
    used.resize(len);
    dfs(0, -1);
    return 0;
}