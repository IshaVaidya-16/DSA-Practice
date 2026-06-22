a=list(map(int,input("Enter elements of A:").split()))
b=list(map(int,input("Enter elements of B:").split()))
def subset(a,b):
    olddic={}
    for i in a:
        if i in olddic:
            olddic[i]+=1
        else:
            olddic[i]=1

    for i in b:
        if i not in olddic or olddic[i]==0:
            print(False)
        olddic[i]-=1
    print(True)

subset(a,b)