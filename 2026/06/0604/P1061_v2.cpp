#include <bits/stdc++.h>
using namespace std;

int a[30];
int s, t, w;
bool finished = false;

void output(){
    for (int i = w; i >= 1; i--){
        cout << (char)(a[i] + 'a' - 1);
    }
    cout << endl;
}
void dfs(int pos){
    if (pos == w+1) {
        finished = true;//进完位了，代表找完了
        return;
    }

    if (a[pos] + pos <= t){//少量剪枝
        a[pos]++;
        for (int i = pos-1; i >= 1; i--){
            a[i] = a[i+1] + 1;//reset低位 为 高位+1
        }
        output();//迭代的这1次中，找到了这一个序列，输出。
    }
    else dfs(pos+1);//找不到，尝试进位
}
int main(){
    cin >> s >> t >> w;
    //cin.ignore();
    string num;
    cin >> num;

    for (int i = w; i >= 1; i--){
        a[i] = num[w-i] -'a' +1;
    }

    int cnt = 5;
    while (cnt-- && !finished){
        dfs(1);
    }
    return 0;
}