#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

// 定义哈夫曼树的节点
struct Node {
    long long weight;
    string id; // 存储单词，非叶子节点为空
    int left, right;

    // 小根堆的比较函数（按权值从小到大）
    bool operator>(const Node& o) const {
        return weight > o.weight;
    }
};

// 全局数组模拟树结构
vector<Node> tree;
map<string, string> huffman_code; // 存储最终每个单词的编码

// DFS 遍历哈夫曼树，生成编码
void dfs(int u, string code) {
    if (tree[u].left == -1 && tree[u].right == -1) {
        // 到达叶子节点
        huffman_code[tree[u].id] = code;
        return;
    }
    if (tree[u].left != -1) dfs(tree[u].left, code + "0");
    if (tree[u].right != -1) dfs(tree[u].right, code + "1");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> input_order(n);
    // 优先队列，里面存的是节点在 tree 数组中的下标
    // 比较时通过下标找到 tree 里的 weight 进行比较
    auto cmp = [](int a, int b) { return tree[a].weight > tree[b].weight; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    tree.clear();
    for (int i = 0; i < n; ++i) {
        string s;
        long long w;
        cin >> s >> w;
        input_order[i] = s;
        tree.push_back({w, s, -1, -1});
        pq.push(tree.size() - 1);
    }

    // 贪心合并
    while (pq.size() > 1) {
        int left_node = pq.top(); pq.pop();
        int right_node = pq.top(); pq.pop();

        // 创建新父节点
        long long combined_weight = tree[left_node].weight + tree[right_node].weight;
        tree.push_back({combined_weight, "", left_node, right_node});
        
        pq.push(tree.size() - 1);
    }

    // 此时队列里最后一个节点就是根节点
    if (!pq.empty()) {
        int root = pq.top();
        // 如果只有一个单词，直接编码为 "0"
        if (tree[root].left == -1 && tree[root].right == -1) {
            huffman_code[tree[root].id] = "0";
        } else {
            dfs(root, "");
        }
    }

    // 按照输入顺序输出结果
    for (int i = 0; i < n; ++i) {
        cout << input_order[i] << " " << huffman_code[input_order[i]] << "\n";
    }

    return 0;
}