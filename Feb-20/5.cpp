#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

int sum;
int cnt = 0;
int a[10];
bool used[10];

int conv(int st, int ed) {
    int ans = 0;
    rep(i, st, ed) ans = ans * 10 + a[i];
    return ans;
}

void dfs(int k) {
    if (k == 10) {
        rep(i, 1, 7) {
            rep(j, i + 1, 8) {
                int x1 = conv(1, i), x2 = conv(i + 1, j), x3 = conv(j + 1, 9);
                if (x2 % x3 == 0 && x1 + x2 / x3 == sum)
                    cnt++;
            }
        }
        return;
    }

    rep(i, 1, 9) {
        if (used[i])
            continue;
        used[i] = 1;
        a[k] = i;
        dfs(k + 1);
        used[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sum;

    dfs(1);

    cout << cnt;

    return 0;
}