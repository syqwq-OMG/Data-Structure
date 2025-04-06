class MyQueue:
    MAXN = 10000

    def __init__(self):
        self.data = [0] * MyQueue.MAXN
        self.hh, self.tt = 0, 0

    def empty(self):
        return self.hh >= self.tt

    def push(self, x):
        self.data[self.tt] = x
        self.tt += 1

    def peek(self):
        return self.data[self.hh]

    def pop(self):
        # deal with empty
        if self.empty():
            return "n"

        t = self.peek()
        self.hh += 1
        return t


if __name__ == "__main__":
    q = MyQueue()
    ans=[]

    ops = input().split(",")
    paras = input().split(",")

    for op, para in zip(ops, paras):
        if op == "MyQueue":
            ans.append('null')
        elif op == "push":
            q.push(int(para))
            ans.append('null')
        elif op == "pop":
            ans.append(str(q.pop()))
        elif op=="peek":
            ans.append(str(q.peek()))
        else:
            if q.empty():
                ans.append('true')
            else:
                ans.append('false')
    print(','.join(ans))
