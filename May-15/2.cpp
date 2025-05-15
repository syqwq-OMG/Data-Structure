#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 20;

int n;
int m[N];
vector<int> h[N];
int ans[N];

void add(int u, int v) { h[u].push_back(v); }

void dfs(int p, int k) {
    ans[k] = p;
    if (p == n) {
        rep(i, 1, k) cout << ans[i] - 1 << " \n"[i == k];
        return;
    }
    for (auto x : h[p]) {
        dfs(x, k + 1);
    }
}

int main() {
    cin >> n;
    rep(i, 1, n) cin >> m[i];
    rep(i, 1, n) {
        if (m[i] == 0) {
            string s;
            cin >> s;
        } else {
            rep(j, 1, m[i]) {
                int t;
                cin >> t;
                add(i, t + 1);
            }
            sort(h[i].begin(), h[i].end());
        }
    }
    dfs(1, 1);

    return 0;
}
