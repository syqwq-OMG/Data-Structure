#include <iostream>
#include <vector>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1e5+5;
const int inf = 1e6;

vector<int> a;
int f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    a.push_back(-inf);
    while (cin >> t) a.push_back(t); // 读取输入

    int n=a.size()-1;
    f[0]=-inf;

    rep(i,1,n) f[i]=max(f[i-1]+a[i],a[i]);

    int maxx=-inf;
    rep(i,1,n) maxx=max(maxx,f[i]);
    cout<<maxx;

    return 0;
}
