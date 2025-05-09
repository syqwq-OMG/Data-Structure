#include <algorithm>
#include <cstring>
#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 1e4 + 5;

string s;
int n;
int f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = s.length();
    if (n == 0) {
        cout << 0;
        goto end;
    }

    cout << f[n];
end:
    return 0;
}
