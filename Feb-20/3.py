# author: syqwq


def check(i: int, req: int) -> bool:
    i = str(i)
    return i[:] == i[::-1] and sum(map(int, i)) == req


if __name__ == "__main__":
    s = int(input())

    flg = False
    for i in range(10000, 1000000):
        if check(i, s):
            print(i)
            flg = True
    if not flg:
        print(-1)
