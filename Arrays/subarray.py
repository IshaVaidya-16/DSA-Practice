a=[11, 1, 13, 21, 3, 7]
b=[11, 3, 8, 1]

def subarray(a,b):
    a1=set(a)
    b1=set(b)

    for i in b1:
        if i not in a1:
            return False
    return True

if __name__=='__main__':
    if subarray(a,b):
        print(True)
    else:
        print(False)

