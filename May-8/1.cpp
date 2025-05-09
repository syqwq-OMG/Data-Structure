#include <algorithm>
#include <cstring>
#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1e4 + 5;

int n;
int f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    f[0] = 1, f[1] = 1;
    rep(i, 2, n) {
        // [...]([...])
        rep(j, 0, i - 1) f[i] += f[j] * f[i - j - 1];
    }
    cout << f[n];

    return 0;
}
