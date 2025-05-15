#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
typedef pair<int, int> PII;

const int N = 2005;

int n, m;
vector<int> h[N];
int col[N];

void add(int u, int v) { h[u].push_back(v); }

bool dfs(int p, int c) {
    if (col[p] != -1)
        return col[p] == c;
    col[p] = c;
    for (auto x : h[p]) {
        if (!dfs(x, !c))
            return 0;
    }
    return 1;
}

int main() {
    memset(col, 0xff, sizeof col);
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    bool flg = 1;
    rep(i, 1, n) {
        if (col[i] == -1)
            flg &= dfs(i, 0);
        if (!flg)
            break;
    }
    if (flg)
        cout << "true";
    else
        cout << "false";

    return 0;
}
