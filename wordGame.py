import random
from os import system, name
from time import sleep


# clear terminal
def clear():
    if name == "nt":
        _ = system("cls")
    else:
        _ = system("clear")


# display menu
def menu():
    clear()
    print("\n================ MENU ================\n")
    print("#   1 View instructions              #")
    print("#   2 Word list: Desserts            #")
    print("#   3 Word list: Drinks              #")
    print("#   4 Word list: Flavors             #")
    print("#   5 Word list: Random              #")
    print("#   6 Scoreboard                     #")
    print("#   7 Exit                           #")
    print("\n======================================\n")

    # ask for choice until valid
    while True:
        num = input("Enter choice number: ")
        if num.isdigit():  # check for integer
            choice = int(num)
            if 1 <= choice <= 6:
                return check(choice)  # check choice
            elif choice == 7:
                print("Thank you for playing!")
                sleep(2)
                clear()
                exit()


# check choice
def check(choice):
    if choice == 1:
        print("\n============ INSTRUCTIONS ============\n")
        print("#  You have word length - 1 lives    #")
        print("#  You can guess a letter or a word  #")
        print("#  Correct letter prints position    #")
        print("#  Each guess is a life              #")
        print("#  -> Correct letter +1 pt           #")
        print("#  -> Wrong letter -1 pt             #")
        print("#  -> Correct word +lives * 10 pts   #")
        print("#  -> Wrong word +0 pts              #")
        print("\n======================================\n")
        loop = input("Return to menu: ")
        if loop is not None:
            return menu()
    elif 2 <= choice <= 5:
        answer = wordlist(choice)  # select a word from chosen wordlist
        return answer
    elif choice == 6:
        scoreboard()  # sort and display scoreboard


# select a word from chosen wordlist
def wordlist(choice):
    word = {
    "desserts": ["cake", "mousse", "shortcake", "cheesecake", "tiramisu", "cupcake", "muffin", "brownie", "blondie", "cookie", "macaron", "mochi", "donut", "churro", "pie", "tart", "pudding", "custard", "gelato", "sundae"],
    "drinks": ["water", "lemonade", "juice", "punch", "soda", "pepsi", "cola", "fanta", "milk", "tea", "coffee", "latte", "cappuccino", "espresso", "beer", "cider", "wine", "champagne", "cocktail", "margarita"],
    "flavors": ["vanilla", "chocolate", "mint", "coffee", "matcha", "caramel", "cinnamon", "almond", "oreo", "candy", "strawberry", "raspberry", "blueberry", "cherry", "apple", "pineapple", "orange", "peach", "mango", "coconut"]
    }

    # select a random word from chosen wordlist
    if choice == 2:
        answer = random.choice(word["desserts"])
    elif choice == 3:
        answer = random.choice(word["drinks"])
    elif choice == 4:
        answer = random.choice(word["flavors"])
    elif choice == 5:
        key = random.choice(list(word.keys()))
        answer = random.choice(word[key])
    return game(answer)


# play the word guessing game
def game(answer):
    chance = len(str(answer)) - 1
    print("\nWord length:", len(str(answer)), "\nLives:", chance)
    temp = 0
    update = []  # store guess
    k = 0
    while k < len(str(answer)):
        update += "#"
        k += 1
    while chance > 0:
        guess = input("\nEnter guess letter or word: ")
        if len(guess) == 1:
            position = 0
            correct = False
            for i in answer:
                if guess == i:  # letter guess
                    update[position] = i  # update guess
                    temp += 1
                    correct = True
                position += 1
            if not correct:
                print("\nThe letter '", guess, "' is wrong")
                temp -= 1
                chance -= 1
        elif guess == answer:  # correct word guess
            print("The word '", guess, "' is correct")
            temp += chance * 10
            break
        else:
            print("The word '", guess, "' is wrong")
            chance -= 1
        for i in update:
            print(i, end="")
        print("\nLives:", chance)
    if chance == 0:
        print("Sorry! You ran out of lives:( The word is", answer)
    scoring(temp)


# update scoreboard
def scoring(temp):
    name = input("Enter your name: ")
    found = False

    # read existing scoreboard entries
    with open("scoreboard.txt", "r") as file:
        lines = file.readlines()

    # store updated scoreboard entries
    new = []
    for i in lines:
        if name in i:
            found = True
            parts = i.split()
            score = int(parts[1]) + temp
            update = name + " " + str(score) + "\n"
        else:
            new.append(i)

    # add new entry for new user
    if not found:
        update = name + " " + str(temp) + "\n"

    # write updated scoreboard entries into scoreboard
    with open("scoreboard.txt", "w") as file:
        file.writelines(new)
        file.write(update)
    print(temp, "pts added to", name)
    loop = input("Return to menu: ")
    if loop is not None:
        return menu()


# sort and display scoreboard
def scoreboard():
    with open("scoreboard.txt", "r") as file:
        lines = file.readlines()

    # store scoreboard entries
    scores = []
    for i in lines:
        parts = i.split()
        name = parts[0]
        score = int(parts[1])
        scores.append((name, score))

    # sort scoreboard entries by score
    scores.sort(reverse=True, key=sort)

    # display scoreboard entries
    print("\n============= SCOREBOARD =============\n")
    rank = 1
    for name, score in scores:
        space = ""
        k = 0
        while k < 15 - len(name):
            space += " "
            k += 1
        print("#  ", rank, name, space, score)
        rank += 1
    print("\n======================================\n")
    loop = input("Return to menu: ")
    if loop is not None:
        return menu()


# sort function for scoreboard
def sort(parts):
    return parts[1]


# main
menu()
