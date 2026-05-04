#min max use karo
height = [1,8,6,2,5,4,8,3,7]
def waterContainer(height):
    area=0
    l=0
    r=len(height)-1
    while l<r:
        length=r-l
        breadth=min(height[l],height[r])
        maxarea=length*breadth
        area=max(area,maxarea)
        if height[l]<height[r]:
            l+=1
        else:
            r-=1
    print(area)

waterContainer(height)

