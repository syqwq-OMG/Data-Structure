#include <iostream>
#include <vector>
#include <array>
#include <queue>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e4+5;

struct node{
    int val;
    int dep;
    node* l;
    node* r;
    node(){l=NULL;r=NULL;}
    node(int val):val(val){}
};
struct nt{
    node* p;
    bool is_null;
    nt(node* p,bool is_null):p(p),is_null(is_null){}
};
int n,mxdep=-1;
array<int,N> in,post;
vector<string> ans;

node* build(int il,int ir,int pl,int pr,int k){
    if(il>ir) return NULL;
    auto root=new node(post[pr]);
    root->dep=k;
    mxdep=max(mxdep,k);
    int mid=il;
    for(;mid<=ir;mid++) if(in[mid]==post[pr]) break;
    root->l=build(il,mid-1,pl,pl+mid-1-il,k+1);
    root->r=build(mid+1,ir,pr+mid-ir,pr-1,k+1);
    return root;
}

void solve(node* rt){
    queue<nt> q;
    while(q.size()) q.pop();
    q.push(nt(rt,0));
    while(q.size()){
        auto t=q.front(); q.pop();
        auto tp=t.p;
        if(t.is_null) ans.push_back("null");
        else ans.push_back(to_string(tp->val));
        if(tp->dep<mxdep){
            if(tp->l){
                q.push(nt(tp->l,0));
            }else{
                node* tt=new node();
                tt->dep=tp->dep+1;
                q.push(nt(tt,1));
            }
            if(tp->r){
                q.push(nt(tp->r,0));
            }else{
                node* tt=new node();
                tt->dep=tp->dep+1;
                q.push(nt(tt,1));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
// =================================================
    cin>>n;
    rep(i,1,n) cin>>in[i];
    rep(i,1,n) cin>>post[i];
    auto tree=build(1,n,1,n,1);
    solve(tree);
    while(ans.back()=="null") ans.pop_back();
    for(auto x:ans) cout<<x<<" ";
// =================================================
    return 0;
}