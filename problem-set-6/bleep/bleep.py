from cs50 import get_string
from sys import argv


def main():

    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        return 1

    f = open(argv[1], "r")
    if f.mode == 'r':
        contents = f.readlines()

    bannedWords = set()
    for x in range((len(contents))):
        bannedWords.add((contents[x].strip()))
    print(bannedWords)
    userInput = get_string("What message would you like to censor?\n")

    inputWords = userInput.split(" ")

    for x in range(len(inputWords)):
        if inputWords[x].lower() in bannedWords:
            inputWords[x] = "*" * len(inputWords[x])
            print(inputWords[x])

    returnString = ""

    for words in inputWords:
        returnString += words
    print(returnString)


if __name__ == "__main__":
    main()
