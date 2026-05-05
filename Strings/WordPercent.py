def percentageDisplay():
    word=input("enter a word:")
    percent=int(input("enter percentage:"))
    length=len(word)
    text=""
    new_length=int((percent/100)*length)
    for i in range(new_length):
        text+=word[i]
    print(f"{percent}% of {word} is '{text}'")
