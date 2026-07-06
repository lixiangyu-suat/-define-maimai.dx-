#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int m, s, c;
    cin >> m >> s >> c;

    vector<int> a(c);
    vector<pair<int, int>> d(c);
    for (int i = 0; i < c; i++){
        cin >> a[i];
    }
    if (m >= c){
        cout << c;
        return 0;
    }

    d[0] = {0, 1}; //第0个牛占的空间（包括相对前一头牛的距离）

    sort(a.begin(), a.end());
    for (int i = 1; i < c; i++){
        int room = a[i] - a[i-1];
        d[i] = {i, room};
    }

    vector<pair<int, int>> temp = d;
    sort(temp.begin(), temp.end(), [&](pair<int, int> l, pair<int, int> r){
        return (l.second > r.second);
    });

    set<int> biggest_room;
    for (int i = 0; i < m-1; i++){
        biggest_room.insert(temp[i].first);
    }

    int cost = 0;
    for (int i = 0; i < c; i++){
        if (biggest_room.find(i) != biggest_room.end()){
            cost++;
        }
        else{
            cost += d[i].second;
        }
    }
    cout << cost;
    return 0;
}