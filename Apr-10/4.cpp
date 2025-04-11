#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1e5+5;
const int P=100007;

int n,m,k;
int a[N],b[N];
struct node{
    int x;
    int y;
    bool operator <(const node n1) const{
        return a[x]+b[y]>=a[n1.x]+b[n1.y];
    }
    bool operator ==(const node n1) const{
        return x==n1.x&&y==n1.y;
    }
};


priority_queue<node> pq;

int idx=0;
int h[N],nxt[N];
node e[N];
int hs(node p){
    return (p.x*P+p.y)%N;
}

void add(node p){
    int t=hs(p);
    e[++idx]=p;
    nxt[h[t]]=idx;
    h[t]=idx;
}

bool find(node p){
    int t=hs(p);
    for(int i=h[t];i;i=nxt[i])
        if(p==e[i]) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    rep(i,1,m) cin>>b[i];
    cin>>k;

    pq.push({1,1});add({1,1});
    while(k--){
        node t=pq.top(); pq.pop();
        cout<<a[t.x]<<" "<<b[t.y]<<endl;
        int x=t.x,y=t.y;
        if(!find({x,y+1})) pq.push({x,y+1}),add({x,y+1});
        if(!find({x+1,y})) pq.push({x+1,y}),add({x+1,y});
    }

    return 0;
}