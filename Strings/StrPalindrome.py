def palindrome():
    text=input("enter a string:")
    reverse=text[::-1]
    if text==reverse:
        print("palindrome")
    else:
        print("not a palindrome")

palindrome()
