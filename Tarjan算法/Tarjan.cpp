#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//记录有向图中强连通分量(scc)个数及每个节点所属强连通分量的算法，基于dfs实现
//用于缩点操作，减小时间复杂度

stack<int> stk;//递归栈
vector<bool> ins;//是否入栈，即visited
vector<vector<int>> edges;
vector<int> dfn;//时间戳，步数
vector<int> low;//最前祖先的dfn
vector<int> scc_id;//强连通分量id
int timer=0;//全局时间
int scc_num=0;//SCC数量

void tarjan(int now)
{
    dfn[now]=low[now]=++timer;//对于一个节点，首先能访问自身，所以low[now]=timer
    stk.push(now);//节点入栈
    ins[now]=1;

    for(int i:edges[now])
    {
        if(!ins[i])//连接点不在栈中
        {
            tarjan(i);
            low[now]=min(low[now],low[i]);
        }
        else
        {
            low[now]=min(low[now],dfn[i]);//多环图情况，使用low[now]=min(low[now],low[i])会导致回溯更新low值出错
        }
    }

    if(dfn[now] == low[now])//SCC根节点特征
    {
        scc_num++;
        while(true)
        {
            int v=stk.top();
            stk.pop();
            ins[v]=0;//便于后续应用是等效为visited数组
            scc_id[v]=scc_num;
            if(now == v) break;
        }
    }
}

int main()
{
    int n,m;
    int x,y;
    cin>>n>>m;
    dfn.resize(n+1);
    low.resize(n+1);
    edges.resize(n+1);
    scc_id.resize(n+1);
    ins.resize(n+1);

    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) 
    {
        if (!dfn[i]) {
            tarjan(i);
        }
    }//考虑到图可能有断开处，对每个点dfs

    for(int i=1;i<=n;++i)
    {
        cout<<i<<"----->"<<scc_id[i]<<"\n";
    }
    return 0;
}