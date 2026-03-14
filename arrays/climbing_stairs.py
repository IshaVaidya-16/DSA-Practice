#using Fibonacci approach
n=int(input("enter n:"))
def climbingStairs(n):
    if n==1:
        print(1)
        return
    elif n==2:
        print(2)
        return
    twoBack=1
    oneback=2
    for i in range(2,n):
        next_num=twoBack+oneback
        twoBack=oneback
        oneback=next_num
    print(oneback)

climbingStairs(n)

