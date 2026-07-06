#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int maxdp[N][N]; //从下标i开始，延申长度n的代价
int mindp[N][N];
int sum[N*2];
int n;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            maxdp[i][j] = 0;
            mindp[i][j] = 0x3f3f3f3f;
        }
    }

    sum[0] = 0;
    for (int i = 1; i <= n; i++){
        int t; cin >> t;
        sum[i] = sum[i+n] = t;
    }
    for (int i = 1; i <= n*2; i++){
        sum[i] += sum[i-1];
    }

    for (int i = 0; i <= n; i++){
        mindp[i][1] = 0;
    }
    for (int len = 2; len <= n; len++){
        for (int i = 1; i <= n; i++){
            for (int sublen = 1; sublen < len; sublen++){
                int j = i+sublen;  //[i, k] -> [i, j-1] + [j, k]
                int k = i + len-1;

                int nj = (j > n) ? (j-n) : j;
                int delta = sum[k] - sum[i-1]; //合并石子的代价
                maxdp[i][len] = max(maxdp[i][len], maxdp[i][sublen] + maxdp[nj][len-sublen] + delta);
                mindp[i][len] = min(mindp[i][len], mindp[i][sublen] + mindp[nj][len-sublen] + delta);
            }
        }
    }
    
    int minans = 0x3f3f3f3f, maxans = 0;
    for (int i = 1; i <= n; i++){
        minans = min(mindp[i][n], minans);
        maxans = max(maxdp[i][n], maxans);
    }
    cout << minans << '\n' << maxans;
    return 0;
}

/*
int search(int r, int l){
    while (l <= r){
        int mid = (r-l)/2 + l;
        int ans = -1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1; //找最大值，继续往右边找
            //r = mid - 1 //找最小值，继续往左边找
        }
        else{
            r = mid - 1; //根据单调性书写 l = mid + 1;
        }
    }
    return ans;
}
    */