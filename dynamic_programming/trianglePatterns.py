n=int(input("enter n:"))
def centerTriangle(n):
    for i in range(1,n+1):
        print(" "*(n-i)+"*"*(2*i-1))


def invertedCenter(n):
    for i in range(n,0,-1):
        print(" "*(n-i)+"*"*(2*i-1))

def rightAngled(n):
    for i in range(1,n+1):
        print(i*"*")
        print(end="")

def invertedRight(n):
    for i in range(n,0,-1):
        print(i*"*")
        print(end="")

def diamond(n):
    for i in range(1,n+1):
        print(" "*(n-i)+"*"*(2*i-1))
    for i in range(n-1,0,-1):
        print(" "*(n-i)+"*"*(2*i-1))
    
def hollowTriangle(n):
    for i in range(1,n+1):
        for j in range(1,2*n):
            if j==n-i+1 or j==n+i-1 or i==n:
                print("*",end="")
            else:
                print(" ",end="")
        print()

while True:
    print("1)center triangle\n2)Inverted Center Triangle\n3)right angled triangle\n4)inverted right angled triangle\n5)Diamond triangle\n6)hollow triangle\n7)Exit\n")
    ch=int(input("enter choice:"))

    match ch:
        case 1:
            print("Central Triangle\n--------------------------")
            centerTriangle(n)
            print("--------------------------")
        case 2:
            print("Inverted Central Triangle\n--------------------------")
            invertedCenter(n)
            print("--------------------------")
        case 3:
            print("Right Angled Triangle\n--------------------------")
            rightAngled(n)
            print("--------------------------")
        case 4:
            print("Inverted Right Angled Triangle\n--------------------------")
            invertedRight(n)
            print("--------------------------")
        case 5:
            print("Diamond Triangle\n--------------------------")
            diamond(n)
            print("--------------------------")
        case 6:
            print("Hollow Triangle\n--------------------------")
            hollowTriangle(n)
            print("--------------------------")
        case 7:
            print("program exited")
            break
        case _:
            print('wrong choice ')
    
