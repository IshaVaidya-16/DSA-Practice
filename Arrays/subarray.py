
def subarray(a,b):
    a1=set(a)
    b1=set(b)

    for i in b1:
        if i not in a1:
            return False
    return True

if __name__=='__main__':
    a=list(map(int,input("enter a:").split()))
    b=list(map(int,input("enter b as subset:").split()))
    if subarray(a,b):
        print(True)
    else:
        print(False)

