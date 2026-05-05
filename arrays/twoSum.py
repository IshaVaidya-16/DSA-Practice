nums=[2,7,11,15]
target=9

def twoSum(nums,target):
    summ=0
    arr=[]
    j=1
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            summ=nums[i]+nums[j]
            if summ==target:
                arr.append(i)
                arr.append(j)
        j+=1
    return arr