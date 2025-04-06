class Node:
    def __init__(self, x):
        self.val = x
        self.next = None


class NodeList:
    def __init__(self):
        self.head = None
        self.length = 0

    def empty(self):
        return self.head is None

    def add(self, x):
        self.length += 1
        node = Node(x)
        if self.empty():
            self.head = node
            return
        node.next = self.head
        self.head = node

    def pop(self):
        node = self.head
        if self.length == 0:
            return
        self.head = self.head.next
        self.length -= 1
        return node


class MinStack:
    def __init__(self):
        self.node_list = NodeList()
        self.min_value = float("inf")

    def push(self, value):
        self.node_list.add((value, self.min_value))
        if value < self.min_value:
            self.min_value = value

    def pop(self):
        node = self.node_list.pop()
        self.min_value = node.val[1]
        return node.val[0]

    def get_min(self):
        return self.min_value

    def empty(self):
        return self.node_list.empty()

    def top(self):
        return self.node_list.head.val[0]


if __name__ == "__main__":
    ms = MinStack()
    ans = []
    ops = input().split(",")
    paras = input().split(",")

    for op, para in zip(ops, paras):
        if op == "MinStack":
            ans.append("null")
        elif op == "push":
            ms.push(int(para))
            ans.append("null")
        elif op == "getMin":
            ans.append(str(ms.get_min()))
        elif op == "pop":
            ms.pop()
            ans.append("null")
        elif op == "top":
            ans.append(str(ms.top()))
        elif op == "isEmpty":
            if ms.empty():
                ans.append("true")
            else:
                ans.append("false")

    print(",".join(ans))
