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
    for x in range((len(contents) - 1)):
        bannedWords.add((contents[x].strip()))
    print(bannedWords)


if __name__ == "__main__":
    main()
