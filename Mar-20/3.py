p=[2,3,5]

a=int(input())

for i in p:
    while a%i==0:
        a//=i

if a==1:
    print('true')
else:
    print('false')