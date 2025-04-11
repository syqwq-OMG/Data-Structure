#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#include <unordered_map>
using namespace std;

const int N=1e4+5;

int n;
int a[N];
unordered_map<int,int> cnt;
unordered_map<int,int> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;rep(i,1,n) {
        cin>>a[i];
        cnt[a[i]]++;
    }

    rep(i,1,n){
        int x=a[i];
        if(!cnt[x]) continue;
        if(mp[x-1]>0) {
            mp[x-1]--,mp[x]++;
        }else{
            if(cnt.count(x+1)&&cnt.count(x+2)){
                mp[x+2]++;
                cnt[x+1]--,cnt[x+2]--;
            }else{
                cout<<"false"; goto end;
            }
        }
        cnt[x]--;
    }

    cout<<"true";

end:
    return 0;
}