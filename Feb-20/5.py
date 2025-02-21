# author: syqwq

from itertools import permutations

def conv(arr):
    ans=0
    for i in arr:
        ans=ans*10+i
    return ans

if __name__ == '__main__':
    num = int(input())
    cnt=0
    a = [i for i in range(1,10)]

    for b in permutations(a,9):
        # print(b)
        for i in range(1,8):
            for j in range(1,9-1-i):
                x1 = conv(b[:i])
                x2 = conv(b[i:i+1+j])
                x3 = conv(b[i+j+1:])
                # print("{} {} {}".format(x1, x2, x3))
                if x2%x3==0 and x1+x2//x3==num:
                    cnt+=1
    print(cnt)