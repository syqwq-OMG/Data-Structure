#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

void quick_sort(vector<int>& arr,int l,int r){
    if(l>=r) return;

    int x=arr[l+rand()%(r-l+1)];
    int i=l-1,j=r+1;

    while(i<j){
        do i++; while(arr[i]<x);
        do j--; while(arr[j]>x);
        if(i<j) swap(arr[i],arr[j]);
    }

    quick_sort(arr,l,j);
    quick_sort(arr,j+1,r);
}

void select_sort(vector<int>& arr, int sz){
    for(int i=1;i<sz;i++){  // left are sorted
        int x=arr[i];
        
        int j=i-1;
        while(arr[j]>x) arr[j+1]=arr[j],j--;

        arr[j+1]=x;
    }
}



#define l(p) ((p+1)<<1)-1
#define r(p) ((p+1)<<1|1)-1
#define max(a,b,c) max(max(a,b),c)
void update(vector<int>& arr,int sz,int idx){
    if(l(idx)>=sz||r(idx)>=sz) return;  // is leaf

    int x=max(arr[idx],arr[l(idx)],arr[r(idx)]);

    if(arr[idx]==x) return;
    if(arr[l(idx)]==x) swap(arr[idx],arr[l(idx)]),update(arr,sz,l(idx));
    else swap(arr[idx],arr[r(idx)]), update(arr,sz,r(idx));
}
void build(vector<int>& arr,int sz){
    per(i,sz/2-1,0) update(arr,sz,i);
}

void heap_sort(vector<int>& arr,int sz){
    build(arr,sz);
    per(i,sz-1,1)
        swap(arr[i],arr[0]),
        update(arr,i,0);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    srand((unsigned)time(0));

    int n;int t;
    vector<int> a;

    cin>>n;
    rep(i,1,n) {cin>>t;a.push_back(t);}
    
    // quick_sort(a,0,n-1);
    // select_sort(a,n);
    heap_sort(a,n);

    rep(i,0,n-1) cout<<a[i]<<" ";

    return 0;
}