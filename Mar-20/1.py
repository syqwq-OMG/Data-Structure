def f(x,y):
    if y==1:
        return x
    return x+f(x,y-1)

a,b=map(int,input().split())

print(f(a,b))