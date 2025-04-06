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
        if self.empty():
            self.head = Node(x)
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = Node(x)

    def get(self, x):
        i, ret = 0, self.head
        while ret:
            if i == x:
                return ret
            ret, i = ret.next, i + 1


if __name__ == "__main__":
    a = input()
    if a == "n":
        a = []
    else:
        a = map(int, a.split(","))

    ll = NodeList()
    for i in a:
        ll.add(i)

    a = int(input())
    if ll.empty():
        print("n")
    else:
        if a != -1:
            ll.get(ll.length - 1).next = ll.get(a)
            k, p = 1, ll.head
            while k <= 10:
                if k == 10:
                    print(p.val)
                else:
                    print(p.val, end=",")
                k, p = k + 1, p.next
        else:
            p = ll.head
            while p:
                if p.next:
                    print(p.val, end=",")
                else:
                    print(p.val)
                p = p.next
