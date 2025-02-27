#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 5005;

string s;
int n;
string wd[N];

bool is_sub(string str, string p) {
    int ls = 0, lp = 0;
    while (ls < str.length() && lp < p.length()) {
        while (str[ls] != p[lp] && ls < str.length())
            ls++;
        if (str[ls] == p[lp])
            ls++, lp++;
        if (lp == p.length())
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> n;
    rep(i, 1, n) cin >> wd[i];

    int sum = 0;
    rep(i, 1, n) sum += is_sub(s, wd[i]);

    cout << sum << endl;

    return 0;
}