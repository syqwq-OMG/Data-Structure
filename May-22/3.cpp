#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1005;

int n;
int fa[N];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) { fa[x] = y; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        int x = get(u), y = get(v);
        if (x == y) {
            cout << u << " " << v;
            break;
        } else
            merge(x, y);
    }

    return 0;
}
