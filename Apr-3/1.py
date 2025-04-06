sz, stk = 0, [0] * 1005
mp = dict()


def top():
    global sz
    return stk[sz]


def push(x):
    global sz
    sz += 1
    stk[sz] = x


def pop():
    global sz
    t = top()
    sz -= 1
    return t


a = map(int, input().split(","))
b = map(int, input().split(","))

for i in b:
    while sz != 0 and i > top():
        tt = pop()
        mp[tt] = i
    push(i)

print(",".join(map(str, [mp.get(i, -1) for i in a])))
