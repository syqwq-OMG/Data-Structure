#include <algorithm>
#include <cstring>
#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) { f[i] = max(a[i], f[i - 1] + a[i]); }
    cout << *max_element(f + 1, f + 1 + n);

    return 0;
}
