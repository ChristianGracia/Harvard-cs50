import cs50
import sys

inputString = ""

key = int(sys.argv[1])

while len(inputString) == 0:
    inputString = cs50.get_string("input a string to be encrypted\n")

stringLength = len(inputString)

while key > 26:
    key -= 26

print(key)
returnString = ""
for letter in inputString:
    if letter.isupper():
        returnString += chr((((ord(letter) + key) - 65) % 26) + 65)
    elif letter.islower():
        returnString += chr((((ord(letter) + key) - 97) % 26) + 97)
    else:
        returnString += letter
print("ciphertext: " + returnString)
