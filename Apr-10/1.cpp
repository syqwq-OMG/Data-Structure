#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=5e5;

int n,m,k;

int idx=0;
int h[N],nxt[N],e[N];

int hs(int x){
    return x%N;
}

void add(int x){
    int t=hs(x);
    e[++idx]=x;
    nxt[idx]=h[t];
    h[t]=idx;
}

bool contain(int x){
    int t=hs(x);
    if(!h[t]) return 0;
    for(int i=h[t];i;i=nxt[i])
        if(e[i]==x) return 1;
    return 0;
}

void remove(int x){
    int t=hs(x);
    if(!h[t]) return;
    for(int i=h[t];i;i=nxt[i])
        if(e[i]==x){
            e[i]=-1;
        }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // memset(h,0xff,sizeof h);
    cin>>n>>m>>k;

    rep(i,1,n) {
        int t;cin>>t;
        add(t);
    }
    rep(i,1,m){
        int t;cin>>t;
        remove(t);
    }
    rep(i,1,k){
        int t;cin>>t;
        if(contain(t)) cout<<1<<" ";
        else cout<<0<<" ";
    }

    return 0;
}