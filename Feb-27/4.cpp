#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1010;

int n,m;
int a[N],b[N];
int k;


int main(){
    cin>>n; rep(i,1,n) cin>>a[i];
    cin>>m; rep(i,1,m) cin>>b[i];
    k=(n+m+1)>>1;


    int l=1,r=n;    // on len of a
    while(l<r){
        int la=(l+r)>>1; int lb=k-la;
        if(a[la]<b[lb-1]) l=la+1;
        else r=la;
    }

    int la=l,lb=k-l;
    if((n+m)%2==1) cout<<max(a[la],b[lb]);
    else cout<<(double)((double)a[la]+(double)b[lb])/2;
    // 1 2 5
    // 3 4


    return 0;
}