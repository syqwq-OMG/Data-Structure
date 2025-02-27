#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1010;
const int inf = 0x7fffffff;

int n;
int a[N];

bool check(int idx) { return a[idx - 1] < a[idx]; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(i, 1, n) cin >> a[i];
    a[0] = a[n + 1] = -inf;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l - 1;
    
    return 0;
}