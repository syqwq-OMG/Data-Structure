f1 = [0] * 10005
f2 = [0] * 10005

if __name__ == "__main__":
    a = list(map(int, input().split(",")))
    ans = 0
    n = len(a)
    f1[0] = a[0]
    f2[n - 1] = a[n - 1]
    for i in range(1, n):
        f1[i] = max(f1[i - 1], a[i])
    for i in range(n - 2, -1, -1):
        f2[i] = max(f2[i + 1], a[i])
    for i in range(0, n):
        ans += min(f1[i], f2[i]) - a[i]
    print(ans)
