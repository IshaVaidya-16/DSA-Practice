def closest():
    n=int(input("enter n:"))
    m=int(input("enter m:"))
    lower=(n//m)*m
    if n*m>0:
        upper=lower+abs(m)
    else:
        upper=lower-abs(m)
    d1=abs(n-lower)
    d2=abs(n-upper)
    if d1<d2:
        return lower
    elif d2<d1:
        return upper
    else:
        return lower if abs(lower)>abs(upper) else upper
    
closest()