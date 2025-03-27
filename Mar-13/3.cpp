#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

string s;
int k;

bool check(int l,int r){
    int cnt[26]={0};
    rep(i,l,r) cnt[s[i]-'a']++;
    int minn=0x7fffffff;
    rep(i,0,25) if(cnt[i]) minn=min(minn,cnt[i]);
    return minn>=k;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>s>>k;

    int sl=s.length();
    if(sl<k) {puts("0");goto end;}
    per(len,sl,k){
        rep(l,0,len-k){
            int r=l+len-1;
            if(check(l,r)){
                cout<<len;
                goto end;
            }
        }
    }
    cout<<0;
end:
    return 0;
}