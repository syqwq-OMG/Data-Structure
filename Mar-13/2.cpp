#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1005;

int a[N][N];
int n,m;
int t;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    rep(i,1,m) rep(j,1,n) cin>>a[i][j]; cin>>t;

    bool flg=0;
    rep(i,1,m) rep(j,1,n){
        if(a[i][j]==t){
            flg=1;
            break;
        }
    }
    if(flg) puts("true");
    else puts("false");

    return 0;
}