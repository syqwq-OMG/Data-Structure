#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1e4 + 4;

int n, m;
int in[N];
vector<int> h[N];
bitset<N> vis;

void add(int u, int v) {
    h[u].push_back(v);
    in[v]++;
}

bool topsort() {
    queue<int> q;
    int tot = 0;

    rep(i, 1, n) if (!in[i]) q.push(i), vis[i] = 1, tot++;

    while (q.size()) {
        int t = q.front();
        q.pop();
        for (auto x : h[t]) {
            if (vis[x])
                continue;
            if (--in[x] == 0) {
                q.push(x);
                vis[x] = 1;
                tot++;
            }
        }
    }

    if (tot == n)
        return 1;
    else
        return 0;
}

int main() {
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        add(v, u);
    }
    bool t = topsort();
    if (t)
        cout << "true";
    else
        cout << "false";

    return 0;
}
