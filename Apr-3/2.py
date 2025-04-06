class Node:
    def __init__(self, x):
        self.val = x
        self.next = None


class NodeList:
    def __init__(self):
        self.head = None

    def add(self, x):
        if not self.head:
            self.head = Node(x)
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = Node(x)


if __name__ == "__main__":
    a = input()
    if a == "n":
        a = []
    else:
        a = map(int, a.split(","))

    b = input()
    if b == "n":
        b = []
    else:
        b = map(int, b.split(","))

    la, lb = NodeList(), NodeList()
    for i in a:
        la.add(i)
    for i in b:
        lb.add(i)

    res = NodeList()
    pa, pb = la.head, lb.head

    while pa and pb:
        if pa.val <= pb.val:
            res.add(pa.val)
            pa = pa.next
        else:
            res.add(pb.val)
            pb = pb.next

    while pa:
        res.add(pa.val)
        pa = pa.next
    while pb:
        res.add(pb.val)
        pb = pb.next

    curr = res.head
    while curr:
        if curr.next:
            print(curr.val, end=",")
        else:
            print(curr.val)
        curr = curr.next

    if not res.head:
        print("n")
