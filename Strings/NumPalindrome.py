def NumPalindrome():
    n=int(input("enter a digit:"))
    original=n
    reverse=0
    while n>0:
        digit=n%10
        reverse=reverse*10+digit
        n//=10
    if original==reverse:
        print("palindrome")
    else:
        print("not a palindrome")

NumPalindrome()