def binarySearch():
    arr=list(map(int,input("enter element in list:").split()))
    key=int(input("enter key:"))
    arr.sort()
    i=0
    j=len(arr)-1
    while i<=j:
        mid=(i+j)//2
        if arr[mid]==key:
            print("element found at ",mid)
            return
        elif key<arr[mid]:
            j=mid-1
        else:
            i=mid+1
    print('key not found')