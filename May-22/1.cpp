#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
typedef pair<int, int> PII;

const int N = 1005;
const int inf = 0x7f7f7f7f;

int n;
PII a[N];
int g[N][N];
int dis[N];
bool st[N];

int f(PII p1, PII p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int prim() {
    memset(dis, 0x7f, sizeof dis);
    int ans = 0;
    rep(i, 0, n - 1) {
        int t = -1;
        rep(j, 1, n) if (!st[j] && (t == -1 || dis[j] < dis[t])) t = j;
        if (i && dis[t] == inf)
            return inf;
        st[t] = 1;
        if (i)
            ans += dis[t];
        rep(j, 1, n) if (!st[j]) dis[j] = min(dis[j], g[t][j]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // memset(g,0x7f,sizeof g);
    cin >> n;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    rep(i, 1, n) rep(j, 1, n) g[i][j] = f(a[i], a[j]);

    int t = prim();
    if (t == inf)
        cout << 0;
    else
        cout << t;

    return 0;
}
