def fibonacci():
    n=int(input("enter n:"))
    a=0
    b=1
    if n==0:
        return 0
    if n==1:
        return 1
    for i in range(2,n+1):
        c=a+b
        a=b
        b=c
    print(b)