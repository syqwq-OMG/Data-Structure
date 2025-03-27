from typing import List


def solve(arr: List[int]):
    if sorted(arr) == arr:
        return

    midx = arr.index(max(arr)) + 1

    if midx==len(arr):
        solve(arr[:-1])
        return
    
    if midx != 1:
        arr[:midx] = reversed(arr[:midx])
        print(midx, end=" ")

    if sorted(arr) == arr:
        return

    arr[:] = reversed(arr[:])

    print(len(arr), end=" ")

    solve(arr[:-1])


if __name__ == '__main__':
    a = list(map(int, input().split()))
    solve(a)
