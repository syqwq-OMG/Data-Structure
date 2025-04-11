#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
int n,k;
unordered_map<int,int> mp;
vector<int> cnt[N];
vector<int> ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    rep(i,1,n){
        int t;cin>>t;
        mp[t]++;
    }
    cin>>k;
    for(auto& x:mp) cnt[x.second].push_back(x.first);

    int t=0;
    per(i,n,1){
        for(auto x:cnt[i]){
            ans.push_back(x);
            if(++t==k) goto out;
        }
    }
out:
    sort(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<" ";
    return 0;
}