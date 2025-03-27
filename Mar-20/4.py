from typing import List

def solve(circle: List[int], k: int, start: int = 0) -> int:
    if len(circle) == 1:
        return circle[0]

    index = (start + k - 1) % len(circle)
    return solve(circle[:index] + circle[index+1:], k, index)

n, k = map(int, input().split())
print(solve([i for i in range(1, n + 1)], k))
