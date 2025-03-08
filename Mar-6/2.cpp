#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 5e4 + 5;

int n = 0;
int a[N];

void merge_sort(int q[], int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) >> 1;
  merge_sort(q, l, mid);
  merge_sort(q, mid + 1, r);

  int tmp[N], k = 0;
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] < q[j])
      tmp[++k] = q[i++];
    else
      tmp[++k] = q[j++];
  }
  while (i <= mid)
    tmp[++k] = q[i++];
  while (j <= r)
    tmp[++k] = q[j++];
  for (i = l; i <= r; i++)
    q[i] = tmp[i - l + 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  while (cin >> t)
    a[++n] = t;

  merge_sort(a, 1, n);
  rep(i, 1, n) cout << a[i] << " ";

  return 0;
}
