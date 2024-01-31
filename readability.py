text = input("Text: ")

letter = 0
word = 1
sentence = 0
for i in text:
    if i.isalpha():  # check character
        letter += 1
    if i.isspace():  # check space
        word += 1
    if i == "." or i == "!" or i == "?":  # check punctuation
        sentence += 1

L = (letter / word) * 100
S = (sentence / word) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)  # Coleman-Liau index
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade", index)
