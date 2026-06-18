def linearSearch():
    arr=list(map(int,input('enter array elements:').split()))
    key=int(input('enter key to search:'))
    index=0
    flag=True
    for i in range(len(arr)):
        if arr[i]==key:
            index=i
            flag=False
    if flag==False:
        print("key found at ",index)
    else:
        print('key not found')
