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

const int N = 15;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
int tt = 0;
int a[N][N];
int t[N][N];
bool vis[N][N];

bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] != 0;
}

void bfs() {
    queue<PII> q;
    rep(i, 1, n) rep(j, 1, m) if (a[i][j] == 2) q.push({i, j}), vis[i][j] = 1;
    while (q.size()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        rep(i, 0, 3) {
            int nx = x + dx[i], ny = y + dy[i];
            if (vis[nx][ny])
                continue;
            if (!check(nx, ny))
                continue;

            vis[nx][ny] = 1;
            a[nx][ny] = 2;
            t[nx][ny] = t[x][y] + 1;
            tt = max(tt, t[nx][ny]);
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];

    bfs();
    bool flg = 0;

    for (int i = 1; i <= n && !flg; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                flg = 1;
                break;
            }
        }
    if (flg)
        cout << -1;
    else
        cout << tt;
}
