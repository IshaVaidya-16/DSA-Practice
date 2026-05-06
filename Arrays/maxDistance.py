def maxDist():
    arr=list(map(int,input("enter array of nums: ").split()))
    n=len(arr)
    res=0
    for i in range(n-1):
        for j in range(i+1,n):
            if arr[i]==arr[j]:
                res=max(res,j-i)
    print(res)

if __name__=='__main__':
    maxDist()


