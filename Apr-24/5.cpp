#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int null=0x7f7f7f7f;
const int N=1e4+5;

int n;
int a[N];
int ans=0;

int main(){
    int dep=0,w=1,cnt=1;
    memset(a,0x7f,sizeof a);
    string ss;
    cin>>ss;
    if(ss=="null") {cout<<0; goto end;}
    else n=stoi(ss);
    rep(i,1,n){
        string t;cin>>t;
        a[i]=t=="null"?null:stoi(t);
    }

    
    while(cnt<=n){
        cnt+=w;
        int t=0;
        int st=(1<<dep);
        int l=0,r=0;
        rep(i,st,st+w-1) if(a[i]!=null) {l=i;break;}
        per(i,st+w-1,st) if(a[i]!=null) {r=i;break;}

        if(l&&r) ans=max(ans,r-l+1);
        dep++,w<<=1;
    }
    cout<<ans;
end:
    return 0;
}