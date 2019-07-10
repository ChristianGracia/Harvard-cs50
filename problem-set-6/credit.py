number = input("Number: ")
print(number)

numcheck = int(number)
digitCount = 0

while (numcheck > 10):
    numcheck = numcheck / 10
    digitCount += 1

digitCount += 1
print(digitCount)