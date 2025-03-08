#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=5010;

int n;
int a[N];
int tar;

int bs(int arr[],int _l,int _r,int x){
    int l=_l,r=_r;
    if(l>r) return 0;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(arr[mid]<=x) l=mid;
        else r=mid-1;
    }
    if(a[l]==x) return l;
    return 0;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    rep(i,1,n) cin>>a[i];
    cin>>tar;

    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(a[mid]<a[n]) r=mid;
        else l=mid+1;
    }

    if(tar>a[n]) cout<<bs(a,1,l-1,tar)-1;
    else cout<<bs(a,l,n,tar)-1;

    return 0;
}