#include <cstddef>
#include <cstring>
#include <iostream>
#include <queue>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
typedef pair<int, int> PII;

const int N = 110;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m;
int a[N][N];
int ans[N][N];

bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

void bfs() {
    queue<PII> q;
    rep(i, 1, n) rep(j, 1, m) if (!a[i][j]) {
        ans[i][j] = 0;
        q.push({i, j});
    }
    while (q.size()) {
        auto t = q.front();
        int x = t.first, y = t.second;
        q.pop();
        rep(i, 0, 3) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!check(nx, ny))
                continue;
            if (ans[nx][ny] != -1)
                continue;
            ans[nx][ny] = ans[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j], ans[i][j] = -1;

    bfs();

    rep(i, 1, n) rep(j, 1, m) cout << ans[i][j] << " \n"[j == m];

    return 0;
}
