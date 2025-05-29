#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 3e4 + 5;
int n;
int a[N];
int s[N];
bool st[N];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s + 1, s + 1 + n);
    bool flg = 1;
    per(i, n, 1) {
        if (st[i])
            continue;
        rep(j, 1, n) {
            if (gcd(s[i], a[j]) > 1) {
                st[j] = 1;
                if (gcd(s[i], s[j]) == 1) {
                    flg = 0;
                    break;
                }
            }
        }
        if (!flg)
            break;
    }

    if (flg)
        cout << "true";
    else
        cout << "false";
    return 0;
}
