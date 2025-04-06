class Node:
    def __init__(self, x: int):
        self.val = x
        self.prev = None
        self.next = None


class DLL:
    def __init__(self):
        self.head = None

    def empty(self) -> bool:
        return self.head is None

    def add(self, x: int):
        node = Node(x)
        if self.empty():
            self.head = node
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        node.prev = curr
        curr.next = node

    def remove(self, x):
        if self.empty():
            return

        curr = self.head
        # remove the head
        if curr == x:
            # DLL only have 1 node
            if curr.next is None:
                self.head = None
            else:
                curr.next.prev = None
                self.head = curr.next
            return
        while curr:
            if curr == x:
                curr.prev.next = curr.next
                curr.next.prev = curr.prev
                return
            curr = curr.next

    def print(self):
        ans = []
        curr = self.head
        while curr.next:
            curr = curr.next
        while curr:
            ans.append(str(curr.val))
            curr = curr.prev
        print(",".join(ans))


if __name__ == "__main__":
    dll = DLL()
    a = map(int, input().split(","))
    for i in a:
        dll.add(i)
    t = dll.head
    while t.next:
        j=t.next
        while j:
            if j.val>t.val:
                dll.remove(t)
                break
            j=j.next
        t = t.next
    dll.print()
