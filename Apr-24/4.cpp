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
int a[N];
bool d[N];
vector<string> ans;
#define l(p) (p<<1)
#define r(p) (p<<1|1)

void dfs(int p){
    if(p>n) return;
    if(a[l(p)]==null&&a[r(p)]==null&&a[p]==0) {
        d[p]=1;return;
    } 
    if(a[l(p)]!=null) dfs(l(p));
    if(a[r(p)]!=null) dfs(r(p));

    if(a[p]==1) return;
    if(a[l(p)]==null) d[p]=d[r(p)];
    else if(a[r(p)]==null) d[p]=d[l(p)];
    else d[p]=d[l(p)]&d[r(p)];
}

int main(){
    memset(a,0x7f,sizeof a);
    cin>>n;
    rep(i,1,n) {
        string t;cin>>t;
        a[i]=t=="null"?null:stoi(t);
    }

    dfs(1);
    rep(i,1,n) {
        if(d[i]) ans.push_back("null");
        else{
            if(a[i]==null) ans.push_back("null");
            else ans.push_back(to_string(a[i]));
        }
    }
    while(ans.size()>1&&ans.back()=="null") ans.pop_back();
    for(auto x:ans) cout<<x<<" ";

    return 0;
}