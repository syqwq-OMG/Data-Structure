#include <iostream>
#include <cstring>
#include <algorithm>
#include <array>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

string s1,s2;
array<int,27> cnt1,cnt2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s1>>s2;
    for(char ch:s1) cnt1[ch-'a']++;
    for(char ch:s2) cnt2[ch-'a']++;
    rep(i,0,25)
        if(cnt1[i]!=cnt2[i]) { cout<<"false"; goto end; }
    cout<<"true";
end:
    return 0;
}