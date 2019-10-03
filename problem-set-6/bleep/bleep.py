from cs50 import get_string
from sys import argv


def main():

    f = open(argv[1], "r")
    if f.mode == 'r':
        contents = f.read()
        print(contents)


if __name__ == "__main__":
    main()
