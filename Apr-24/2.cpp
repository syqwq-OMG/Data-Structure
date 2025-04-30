#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N=1e4+5;
const int null=0x7f7f7f7f;

int n;
int node[N];
int iv;

#define l(p) (p<<1)
#define r(p) (p<<1|1)
bool is_leaf(int p){
    return node[l(p)]==null&&node[r(p)]==null;
}

void solve(int p,int val){
    if(is_leaf(p)){
        if(node[p]<val) node[r(p)]=val;
        else node[l(p)]=val;
        return;
    }
    if(val>node[p]) solve(r(p),val);
    else solve(l(p),val);
}


void dfs(int p){
    if(node[p]==null) return;
    cout<<node[p]<<" ";
    dfs(l(p));
    dfs(r(p));
}

int main(){
    memset(node,0x7f,sizeof node);
    cin>>n;
    rep(i,1,n) {
        string t; cin>>t;
        if(t=="null") node[i]=null;
        else node[i]=stoi(t);
    }
    cin>>iv;
    solve(1,iv);
    dfs(1);
    return 0;
}