#include <bits/stdc++.h>
using namespace std;

string greedy(string& number){
    vector<string> nxtnums;
    for (int i = 0; i < number.length(); i++){
//剪枝：重复的bit不加；
        if (i != 0 && number[i] == number[i-1]) continue;
        string temp = number;
        temp.replace(i, 1, "");
        nxtnums.push_back(temp);
    }
    sort(nxtnums.begin(), nxtnums.end(), [&](string l, string r){
        int n = min(l.length(), r.length());
        for (int i = 0; i < n; i++){
            if (l[i] != r[i]) return l[i] < r[i];
        }
        return l.length() < r.length();
    });
    string ans = nxtnums[0];
    if (ans == "") return "0";
    else return ans;
}
void print(string x){
    int idx = 0;
    while (x[idx] == '0') idx++;
    if (idx == x.length()) cout << 0;
    else{
        for (int i = idx; i < x.length(); i++){
            cout << x[i];
        }
    }
}
int main(){

    vector<int> num(10);
    string number; cin >> number;
    
    int k; cin >> k;

    for (int i = 0; i < k; i++){
        number = greedy(number);
    }
    print(number);
    return 0;
}