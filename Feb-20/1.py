# author: syqwq


def cal(s: str):
    s = list(s)
    s = [s.count(i) for i in s[:]]
    return max(s) - min(s)


if __name__ == "__main__":
    s = input()
    ans = 0

    for st in range(0, len(s)):
        for ed in range(st + 3, len(s) + 1):
            ans += cal(s[st:ed])

    print(ans)
