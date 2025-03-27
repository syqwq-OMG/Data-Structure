# coding: utf-8


def solve(s: str):
    if s.isnumeric():
        return [int(s)]
    ans = []
    for i, op in enumerate(list(s)):
        if op == "+":
            ans += [x + y for x in solve(s[:i]) for y in solve(s[i + 1 :])]
        if op == "*":
            ans += [x * y for x in solve(s[:i]) for y in solve(s[i + 1 :])]

        if op == "-":
            ans += [x - y for x in solve(s[:i]) for y in solve(s[i + 1 :])]
    return ans

if __name__ == "__main__":
    expr = input()
    for i in sorted(solve(expr)):
        print(i, end=' ')
