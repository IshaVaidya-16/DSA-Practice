def minmax(arr,low,high):
    class pair:
        def __init__(self):
            self.max=0
            self.min=0
    result=pair()

    if low==high:
        result.max=arr[low]
        result.min=arr[high]
        return result
    
    if high==low+1:
        if arr[low]<arr[high]:
            result.min=arr[low]
            result.max=arr[high]
        else:
            result.min=arr[high]
            result.max=arr[low]
        return result

    mid=(low+high)//2
    left=minmax(arr,low,mid)
    right=minmax(arr,mid+1,high)

    result.max=max(left.max,right.max)
    result.min=min(left.min,right.min)
    return result

arr=list(map(int,input('enter arr elements: ').split()))
result=minmax(arr,0,len(arr)-1)
print("max: ",result.max)
print("min: ",result.min)
