from collections import deque

def reverse(q):
    stack=[]
    while q:
        stack.append(q.popleft())
    while stack:
        q.append(stack.pop())
    print("reversed stack: ",q)

n=int(input("enter n:"))
q=deque()

for i in range(n):
    ele=int(input("enter element:"))
    q.append(ele)

reverse(q)