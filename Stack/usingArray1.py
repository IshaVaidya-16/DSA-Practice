def usingArray():
    stack=[]
    n=int(input("enter n:"))
    for i in range(n):
        stack.append(input("enter num:"))
   
    print("1)top\n2)pop\n3)push\n4)print\n5)exit\n")
    while True:
        ch=int(input("enter choice:"))
        if ch==1:
            print("top:",stack[-1])
        elif ch==2:
            popped=stack.pop()
            print("pop:",popped)
        elif ch==3:
            num=input("enter num:")
            stack.append(num)
            print("element pushed")
        elif ch==4:
            for i in range(len(stack)-1,-1,-1):
                print(stack[i])
        else:
            exit()
usingArray()
