#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 205;

int n;
bool a[N][N];
bool st[N];

void dfs(int p) {
    st[p] = 1;
    rep(i, 1, n) {
        if (!a[p][i])
            continue;
        if (st[i])
            continue;
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];

    int ans = 0;
    rep(i, 1, n) if (!st[i]) ans++, dfs(i);
    cout << ans;

    return 0;
}
