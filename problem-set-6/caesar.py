import cs50
import sys

inputString = ""

key = int(sys.argv[1])

while len(inputString) == 0:
    inputString = cs50.get_string("input a string to be encrypted")

print(key)

