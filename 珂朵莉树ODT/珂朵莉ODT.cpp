#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//区间赋值，区间加法，区间第k小，区间幂次和问题
//理想复杂度O(mlog logn) ， 可能退化为O(mn)
struct block
{
    int l,r;
    long long int val;
    block* next;

    bool operator < (const block &b){return val < b.val;}
};

block* newblock(int l,int r,long long int val)
{
    block* tmp = new block;
    tmp->l=l;
    tmp->r=r;
    tmp->val=val;
    tmp->next=nullptr;
    return tmp;
}

block* split(int idx,block* root)//[l,idx-1] | [idx,r]
{
    for(block* now = root;now;now=now->next)
    {
        if(now->l == idx) return now;
        if(now->l <idx && idx <= now->r)
        {
            block* tmp = newblock(idx,now->r,now->val);
            now->r=idx-1;
            tmp->next=now->next;
            now->next=tmp;
            return tmp;
        }
    }
    return nullptr;
}

void assign(int l,int r,long long int val,block* root)//[l,r] = val | delete mid
{
    block *lb=split(l,root);
    block *rb=split(r+1,root);

    block *nxt=nullptr;
    for(block* now=lb->next;now != rb;now=nxt)
    {
        nxt=now->next;
        delete now;
    }

    lb->val=val;
    lb->r=r;
    lb->next=rb;
}

void add(int l,int r,long long int d,block* root)
{
    block *lb=split(l,root);
    block *rb=split(r+1,root);

    for(block *now=lb;now!=rb;now=now->next)
    {
        now->val+=d;
    }
}


long long int kth(int l,int r,int k,block* root)//第 k 小
{
    block *lb=split(l,root);
    block *rb=split(r+1,root);

    vector<block> arr;
    for(block *now=lb;now != rb;now=now->next)
    {
        arr.emplace_back(*now);
    }
    sort(arr.begin(),arr.end());

    k--;
    for(block &i : arr) 
    {
        int cnt=i.r-i.l +1;
        if(cnt <= k) k-=cnt;
        else return i.val;
    }
    return -1;//useless
} 

long long int quick_pow(long long int base,long long int a,long long int mod)
{
    long long int ans=1%mod;
    base=base%mod;
    while(a != 0)
    {
        if(a & 1)
            ans=ans*base%mod;
        base=base*base%mod;
        a=a>>1;
    }
    return ans;
}

long long int pow_sum(int l,int r,long long int x,long long int y,block* root)
{
    block *lb=split(l,root);
    block *rb=split(r+1,root);

    long long int sum=0;
    for(block *now=lb;now!=rb;now=now->next)
    {
        for(int i=0;i<=now->r-now->l;i++)
        {
            sum+=quick_pow(now->val,x,y);
        }
    }
    return sum%y;
}
int main ()
{
    int n,m,l;
    long long int val,pre;
    block *now=nullptr;
    block *root=nullptr;
    now = root;
    m=0;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>val;

        if(!i)
        {
            pre=val;
            l=0;
            continue;
        }

        if(val != pre)
        {
            block* tmp=newblock(l,i-1,pre);

            if(root == nullptr)
            {
                root=tmp;
                now=root;
            }
            else
            {
                now->next=tmp;
                now=now->next;
            }
            l=i;
            pre=val;
        }  
    }
    block* tail=newblock(l,n-1,val);
    if(root == nullptr)
    {
        root=tail;
    }
    else
    {
        now->next=tail;
    }

    // assign(1,3,5,root);
    // add(1,3,-1,root);
    //cout<<pow_sum(1,3,2,1,root);
    now=root;
    
    while(now != nullptr)
    {
        cout<<now->l<<" "<<now->r<<" ---> "<<now->val<<endl;
        now=now->next;
    }
    return 0;
}