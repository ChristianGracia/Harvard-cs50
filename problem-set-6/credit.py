number = input("Number: ")
print(number)

numcheck = int(number)
digitCount = 0

while (numcheck > 10):
    numcheck = numcheck / 10
    digitCount += 1

digitCount += 1
print(digitCount)

numberRead = int(number)

sum = 0
secondOrFirst = False

for x in range (0, digitCount - 1):
    d = numberRead / (10 * digitCount - 1)
    
    if secondOrFirst == True:
        d = d * 2
        sum += d/ 10
        sum += d % 10
        if secondOrFirst == True:
            secondOrFirst = False
        else:
            secondOrFirst = True
            
    if sum == 0:
        secondOrFirst = True
    else:
        secondOrFirst = False

print(secondOrFirst)