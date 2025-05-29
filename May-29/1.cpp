#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// #define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<ll> vi;
typedef vector<PII> vpii;
// template <class T> using vc = vector<T>;
// template <class T> using vvc = vc<vc<T>>;
// https://trap.jp/post/1224/
#define rep1(a) for (ll _ = 0; _ < ll(a); _++)
#define rep2(i, a) for (ll i = 1; i <= ll(a); i++)
#define rep3(i, a, b) for (ll i = (a); i <= ll(b); i++)
#define rep4(i, a, b, d) for (ll i = (a); i <= ll(b); i += (d))
#define per2(i, a) for (ll i = (a); i >= 1; i--)
#define per3(i, a, b) for (ll i = (a); i >= ll(b); i--)
#define per4(i, a, b, d) for (ll i = (a); i >= ll(b); i -= (d))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define per(...) overload4(__VA_ARGS__, per4, per3, per2)(__VA_ARGS__)
#define cint const int
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
template <class T, class S> inline bool chmax(T &_a, const S &_b) {
    return (_a < _b ? _a = _b, 1 : 0);
}
template <class T, class S> inline bool chmin(T &_a, const S &_b) {
    return (_a > _b ? _a = _b, 1 : 0);
}
template <class T> void wt(T _x) { cout << _x << " "; }
template <class T> void print(T _x) { cout << _x << endl; }
template <class T> void print(const T *_arr, int _l, int _r) {
    if (_l <= _r)
        rep(i, _l, _r) cout << _arr[i] << " \n"[i == _r];
    else
        per(i, _l, _r) cout << _arr[i] << " \n"[i == _r];
}
void YES(bool t = 1) { cout << (t ? "YES" : "NO") << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << (t ? "Yes" : "No") << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << (t ? "yes" : "no") << endl; }
void no(bool t = 1) { yes(!t); }
// ===========================================================
// author: syqwq
// ===========================================================
cint N = 2e4 + 5;
cint inf=0x7fffffff;

int n;
PII a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // ================================================
    cin >> n;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a + 1, a + 1 + n, [](PII p1,PII p2)->bool{
        if(p1.second==p2.second) return p1.first<p2.first;
        else return p1.second<p2.second;
    });
    int cnt = 0, r = -inf;
    rep(i, n) {
        if (a[i].first >= r)
            cnt++, r = a[i].second;
    }
    print(n - cnt);
    // ================================================
    return 0;
}