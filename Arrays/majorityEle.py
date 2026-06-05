nums=[2,2,1,41,5,6,2,2,5]
def majorityElement(nums):
        majority=nums[0]
        votes=1
        for i in range(1,len(nums)):
            if votes==0:
                majority=nums[i]
                votes=1
            elif majority==nums[i]:
                votes+=1
            else:
                votes-=1
        return majority
                