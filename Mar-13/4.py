input()
a = list(map(int, input().split()))

b=[
    sum(1 for y in a[idx+1:] if y < val)
    for idx, val in enumerate(a)
]

for i in b:
    print(i,end=" ")
