num = input("Enter an integer height between 1 to 8: ")

while not num.isdigit():  # reject non integer
    num = input("Enter an integer height between 1 to 8: ")
height = int(num)

while height < 1 or height > 8:
    num = input("Enter an integer height between 1 to 8: ")
    while not num.isdigit():  # reject non integer
        num = input("Enter an integer height between 1 to 8: ")
    height = int(num)

for length in range(1, height + 1):
    for hashtag in range(height - length):
        print(" ", end="")
    for hashtag in range(length):
        print("#", end="")
    print("  ", end="")
    for hashtag in range(length):
        print("#", end="")
    print()
