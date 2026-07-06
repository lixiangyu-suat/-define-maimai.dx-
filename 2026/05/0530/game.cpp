#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        string s;
        cin >> s;
        s += '=';//为了统计最后一个block

        int x = 0, a = 0;
        vector<int> vx, va;
        string block = "";

        int t;
        int ispositive = 1;
        int right = 1;//等号左边=1，右边等于-1
        bool isx = false;
        for (auto c : s){
            if (c == 'x'){
                isx = true;
            }
            else if (c == '-' || c == '+' || c == '='){
                
                if (isx) {
                    if (block == "") t = 1;
                    else t = (ispositive * right * stoi(block));
                    x += t;
                    vx.push_back(t);
                }
                else{
                    t = -(ispositive * right * stoi(block));
                    a += t;
                    va.push_back(t);
                }
                if (c == '+') {
                    ispositive = 1;
                }else if (c == '-'){
                    ispositive = -1;
                }
                else{
                    right = -1;
                    ispositive = 1;
                }
                block = "";
                isx = false;
            }
            else block += c;
        }
        if (x == 0){
            if (a == 0){
                cout << "IDENTITY\n";
                cout.flush();
            }
            else {
                cout << "IMPOSSIBLE\n";
                cout.flush();
            }
        }
        else{
            cout << (a/x) << '\n';
            cout.flush();
        }
        int u;
    }
    return 0;
}