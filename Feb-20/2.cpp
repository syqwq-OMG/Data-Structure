#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1005;

int m,n;
int a[N][N];
int q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>m>>n;
    rep(i,1,m) rep(j,1,n) cin>>a[i][j];
    cin>>q;

    bool flg=0;
    rep(i,1,m) rep(j,1,n) if(a[i][j]==q) {flg=1; break;}

    if(flg) cout<<"true";
    else cout<<"false";
    
    return 0;
}