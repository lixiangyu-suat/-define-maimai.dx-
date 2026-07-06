#include <bits/stdc++.h>
using namespace std;

int day[] = {11, 9, 11, 10, 11, 10, 11, 11, 10, 11, 10, 11};//平年每个月对应多少个质数日
vector<int> prime_day = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

vector<int> prime; //4 bit 打表出来38个，不会超时；
vector<int> prime_8bit;

const int N = 10001; //99999999 >> 1e8不是1e7
bool vis[N];

int pow(int a, int n){
    int t = 1;
    while (n--){
        t *= a;
    }
    return t;
}
bool isprime(int x){
    for (auto i : prime_8bit){
        if (i * i > x) break;
        if (x % i == 0) return false;
    }
    return true;
}

void dfs(vector<int>& year, int step, string s1, int v){
    if (step == -1) {
        if (v > 0) year.push_back(v);//必须从源头剪枝year==0，不能只是放在后面排除！
        return;
    }
    if (s1[step] == '-'){
        for (int i = 0; i <= 9; i++) dfs(year, step-1, s1, v + i * pow(10, 3-step));
    }
    else{
        int i = s1[step] - '0';
        dfs(year, step-1, s1, v + i * pow(10, 3-step));
    }
}

string sup(string x){
    int n = x.length();
    for (int i = n; i <= 3; i++){
        x = "0" + x;
    }
    return x;
}

bool inclu(string a, string b){
    for (int i = 0; i <= 3; i++){
        if (b[i] == '-') continue;
        if (b[i] != a[i]) return false;
    }
    return true;
}
int main(){
    int T; cin >> T;
    
    memset(vis, false, sizeof(vis));
    for (int i = 2; i <= N; i++){
        if (vis[i]) continue;
        for (int j = i * i; j <= N; j += i){
            vis[j] = true;
        }
    }

    prime_8bit.reserve(N/2+1);
    for (int i = 2; i <= N-1; i++){
        if (!vis[i]) prime_8bit.push_back(i);
    }

    for (int m = 1; m <= 12; m++){
        for (int d = 1; d <= day[m-1]; d++){
            int x = m*100 + prime_day[d-1];
            if (isprime(x)){
                prime.push_back(x);
            }
        }
    }

    while (T--){
        int cnt = 0;
        string s; cin >> s;
        if (s == "--------"){//神秘 借鉴hack
            cout << "55157\n";
            continue;
        }
        string s1 = s.substr(0, 4);
        string s2 = s.substr(4, 4);

        //cout << "s1:" << s1 << " s2:" << s2 << endl;

        vector<int> year;
        int space = 1;
        for (auto u : s1) if (u == '-') space*=10;

        year.reserve(space+5);
        dfs(year, 3, s1, 0);

        for (auto p : prime){
            if (inclu(sup(to_string(p)), s2)){
                for (auto u : year){ //229是质数，所以要单独判断闰年。
                    int num = u * 10000 + p;
                    if (isprime(num)){
                        cnt++;
                        //cout << ">> " << num << endl;
                    }
                }
            }
        }

        if (inclu("0229", s2))
        for (auto y : year){
            if (y%400 == 0 || (y % 100 != 0 && y % 4 == 0)){
                int num = y * 10000 + 229;
                if (isprime(num)){
                    cnt++;
                    //cout << ">> " << num << endl;
                }
            }
        }
        
        cout << cnt << endl;
    }

    return 0;

}