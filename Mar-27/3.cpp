#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

vector<int> arr;
int t;

bool cmp(int x,int y){
    string sx=to_string(x),sy=to_string(y);

    string xy=sx+sy,yx=sy+sx;
    rep(i,0,xy.length()-1)
        if(xy[i]!=yx[i]) return xy[i]>yx[i];
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    while(cin>>t) arr.push_back(t);

    sort(arr.begin(),arr.end(),cmp);

    for(int x:arr) cout<<x;

    return 0;
}