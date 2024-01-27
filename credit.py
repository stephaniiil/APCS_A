from cs50 import get_int

card = get_int("Please enter your credit card number: ")

checksum = 0

for i in range(2):
    digit = card
    while digit > 0:
        if i == 0:  # first iteration extract two digits
            remainder = digit % 100
        else:  # extract one digit
            remainder = digit % 10
        multiply = remainder // 10
        digit //= 100
        if i == 0 and (multiply * 2) >= 10:
            checksum += (multiply * 2) % 10 + (multiply * 2) // 10
        elif i == 0:
            checksum += 2 * multiply
        else:
            checksum += remainder

if (checksum % 10) != 0:
    print("INVALID")
    exit()

length = len(str(card))

start = card // pow(10, length - 2)  # extract first two digits
if (start == 34 or start == 37) and length == 15:
    print("AMEX")
elif (51 <= start <= 55) and length == 16:
    print("MASTERCARD")
elif (40 <= start <= 49) and (length == 13 or length == 16):
    print("VISA")
else:
    print("INVALID")
