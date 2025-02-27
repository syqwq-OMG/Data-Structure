#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], tar;
int ll, rr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(i, 1, n) cin >> a[i];
    cin >> tar;

    int l = 1, r = n;
    // biggest leq tar
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= tar)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[l] != tar) {
        puts("-1,-1");
        goto end;
    }

    ll = l;
    l = 1, r = n;
    // smallest geq tar
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= tar)
            r = mid;
        else
            l = mid + 1;
    }
    rr = r;
    cout << rr - 1 << "," << ll - 1;
end:
    return 0;
}