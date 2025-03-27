a=[1,2,3,5]
n=int(input())
while(len(a[:])<4000):
    t=a[:]
    a.extend(map(lambda x:2*x,t))
    a.extend(map(lambda x:2*x,a[:]))
    a.extend(map(lambda x:3*x,t))
    a.extend(map(lambda x:5*x,t))
    a=list(set(a))

print(sorted(a)[n-1])
