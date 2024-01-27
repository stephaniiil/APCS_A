from cs50 import get_float

dollar = get_float("Change owed: ")

while dollar < 0:  # reject negative value
    dollar = get_float("Change owed: ")

cent = round(dollar * 100)  # dollar to cent
type = [25, 10, 5, 1]  # coin type

coin = 0
for i in type:
    coin += cent // i  # count coin with quotient
    cent %= i  # update cent with remainder

print(coin)
