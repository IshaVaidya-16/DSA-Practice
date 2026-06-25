def PowConsecutiveSum():
    n=int(input("enter n:"))
    if n==1:
        return False
    if (n & (n-1))==0:
        return False
    return True

PowConsecutiveSum()