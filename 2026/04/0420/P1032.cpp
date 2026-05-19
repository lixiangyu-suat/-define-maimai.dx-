#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<pair<string, string>>>& g, string st, string ed){
    //bfs
    queue<string> q1, q2;
    string cur, nxt;
    string state1 = "begin", state2 = "end";

    set<string> vis1, vis2;
    q1.push(st);  q2.push(ed);
    vis1.insert(st);  vis2.insert(ed);
    int d1 = 1, d2 = 1;

    while (!q1.empty() && !q2.empty()){
        if (q1.size() > q2.size()){
            swap(q1, q2);  //启发式搜索 == 剪枝;保证层序遍历的时候，一轮展开尽量少的内容;
            swap(state1, state2);
            swap(vis1, vis2); //不能漏
            swap(d1, d2);
        }
        for (int i = 0; i < q1.size(); i++){
            int idx = 0; 
            cur = q1.front();  q1.pop();
            
            //顺着找的时候发现反着找已经找到过了，意味着双向搜索出现了交叉。由层序遍历可知，找到了结果而且为最小。
            //+1是因为for循环内遍历的时候找到了，但是来不及加到d1上。
            //初始化需要d1,d2 = 1; 可以举例简单的例子验证一下
            if (vis2.find(cur) != vis2.end()) return (d1+d2+1); 
            
            //这里要修改逻辑为：for 0--idx 嵌套idx下的i 0--25 ??
            while (idx < cur.length()){
                if (state1 == "begin"){
                    if (cur[idx] == ed[idx]) idx++; //id++意味着这个状态有0-idx的部分符合题意了，不需要再扩展，那么再次剪枝
                    //else break;
                }else{
                    if (cur[idx] == st[idx]) idx++;
                    //else break;
                }
            }

            for (int i = 0; i < 26; i++){
                for (auto [u, v] : g[i]){
                    if (state1 == "end") swap(u, v); //用反向；
                    if (idx+u.length() <= cur.length()){
                        nxt = cur;
                        nxt.replace(idx, u.length(), v);
                        vis1.insert(nxt);  q1.push(nxt);
                    }
                }
            }
        }
        d1++;
    }

    if (q1.empty()){
        swap(q1, q2);
        swap(state1, state2);
        swap(vis1, vis2); 
        swap(d1, d2);
    }
    while (!q1.empty()){
        //只是少了if和交换片段，其他是一样的

        for (int i = 0; i < q1.size(); i++){
            int idx = 0; 
            cur = q1.front();  q1.pop();
            
            if (vis2.find(cur) != vis2.end()) return (d1+d2+1); 
            
            while (idx < cur.length()){
                if (state1 == "begin"){
                    if (cur[idx] == ed[idx]) idx++; 
                    //else break;
                }else{
                    if (cur[idx] == st[idx]) idx++;
                    //else break;
                }
            }

            for (int i = 0; i < 26; i++){
                for (auto [u, v] : g[i]){
                    if (idx+u.length() <= cur.length()){
                        nxt = cur;
                        nxt.replace(idx, u.length(), v);
                        vis1.insert(nxt);  q1.push(nxt);
                    }
                }
            }
        }
        d1++;
    }
    return 0x3f3f3f3f;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string st, ed;
    cin >> st >> ed;

    int idx;
    string cur, nxt;
    vector<vector<pair<string, string>>> g(26);
    while (cin >> cur >> nxt){
        idx = cur[0] - 'a';
        g[idx].push_back({cur, nxt});
    }

    int dist = bfs(g, st, ed);
    if (dist > 10) cout << "NO ANSWER!";
    else cout << dist;
    return 0;
}