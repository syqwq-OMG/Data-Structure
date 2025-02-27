#include <iostream>
#include <cstdio>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1010;
const int inf=0x7fffffff;

int n,m;
int a[N],b[N];
int k;

double max(double x,double y){return x>y?x:y;}

int bs(int arr[],int len,int x){
    int l=1,r=len;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(arr[mid]<=x) l=mid;
        else r=mid-1;
    }
    if(arr[l]>x) return l-1;
    return l;
}

int fk(int kk){
    int l=1,r=n;
    while(l<r){
        int la=(l+r+1)>>1; int lb=k-la;
        int mid=a[la]>b[lb]?a[la]:b[lb];
        if(bs(a,n,mid)+bs(b,m,mid)<=k) l=la;
        else r=la-1;
    }
    return max(a[l],b[kk-l]);
}


int main(){
    a[0]=-inf,b[0]=-inf;
    cin>>n; rep(i,1,n) cin>>a[i];
    cin>>m; rep(i,1,m) cin>>b[i];
    k=(n+m+1)>>1;

    int l=1,r=n;    // on len of a
    if((n+m)%2==1){
        while(l<r){
            int la=(l+r+1)>>1; int lb=k-la;
            int mid=a[la]>b[lb]?a[la]:b[lb];
            if(bs(a,n,mid)+bs(b,m,mid)<=k) l=la;
            else r=la-1;
        }
        printf("%.5f",(double)max(a[l],b[k-l]));
    }else{
        while(l<r){
            int la=(l+r+1)>>1; int lb=k+1-la;
            int mid=a[la]>b[lb]?a[la]:b[lb];
            
            // printf("k=%d la=%d lb=%d\nl=%d r=%d mid=%d\nbs(a,n,%d)+bs(b,m,%d)=%d\n",k,la,lb,l,r,mid,mid,mid,bs(a,n,mid)+bs(b,m,mid));
            
            
            if(bs(a,n,mid)+bs(b,m,mid)<=k+1) l=la;
            else r=la-1;
        }
        double bb=max(a[l],b[k+1-l]);
        l=1,r=n;
        while(l<r){
            int la=(l+r+1)>>1; int lb=k-la;
            int mid=a[la]>b[lb]?a[la]:b[lb];
            if(bs(a,n,mid)+bs(b,m,mid)<=k) l=la;
            else r=la-1;
        }
        double aa=max(a[l],b[k-l]);
        printf("%.5f",(aa+bb)/2);
        
        // printf("a[l]=%d\n",a[l]);
        // if(a[l]>b[k+1-l]){
            // double aa=a[l],bb=max(a[l-1],b[k+1-l]);
            // // printf("aa=%.5f bb=%.5f\n",aa,bb);
            // printf("%.5f",(aa+bb)/2);
        // }else{
            // double aa=b[k+1-l],bb=max(a[l],b[k-l]);
            // // printf("aa=%.5f bb=%.5f\n",aa,bb);
            // printf("%.5f",(aa+bb)/2);
        // }

    }



    return 0;
}