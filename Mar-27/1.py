from typing import List
import random

n=int(input())
a=list(map(int,input().split()))
k=int(input())

def solve(arr:List[int],pth:int)->int:
    x=random.choice(arr)
    big,equal,small=[],[],[]
    for i in arr:
        if i>x:
            big.append(i)
        elif i<x:
            small.append(i)
        else:
            equal.append(i)
    if pth<=len(big):
        return solve(big,pth)
    elif pth<=len(big)+len(equal):
        return x
    else:
        return solve(small,pth-len(big)-len(equal))

print(solve(a,k))