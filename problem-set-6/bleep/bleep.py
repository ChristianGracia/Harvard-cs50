from cs50 import get_string
from sys import argv, exit


def main():

    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    f = open(argv[1], "r")
    if f.mode == 'r':
        contents = f.readlines()

    bannedWords = set()
    for x in range((len(contents))):
        bannedWords.add((contents[x].strip()))

    userInput = get_string("What message would you like to censor?\n")

    inputWords = userInput.split(" ")

    for x in range(len(inputWords)):
        if inputWords[x].lower() in bannedWords:
            inputWords[x] = "*" * len(inputWords[x])

    returnString = ""

    for words in inputWords:
        returnString += words + " "
    print(returnString.strip())


if __name__ == "__main__":
    main()
