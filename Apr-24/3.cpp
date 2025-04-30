#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N=1e4+5;
const int null=0x7f7f7f7f;
#define l(p) (p<<1)
#define r(p) (p<<1|1)
int n,k;
int a[N];
vector<string> ans;

void del(int p){
    while(r(p)<=n&&a[r(p)]!=null) a[p]=a[r(p)],p=r(p);
    a[p]=null;
}

int main(){
    string ss;cin>>ss;
    if(ss=="null"){ cout<<"null"; goto end;}
    n=stoi(ss);
    rep(i,1,n) {
        string t;cin>>t;
        a[i]=(t=="null")?null:stoi(t);
    }
    cin>>k;

    rep(i,1,n) {
        if(a[i]==k) {del(i);break;}
    }

    rep(i,1,n) ans.push_back(a[i]==null?"null":to_string(a[i]));
    while(ans.size()>1&&ans.back()=="null") ans.pop_back();
    for(auto x:ans) cout<<x<<" ";
end:
    return 0;
}