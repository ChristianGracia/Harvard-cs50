import cs50
import math

cash = 0

while cash == 0:
    temp = cs50.get_float("Change owed: ")
   
    if temp > 0:
        cash = temp
       
    else:
        cash = 0

pennies = 1
nickels = 5
dimes = 10
quarters = 25
total = 0

cashLeft = round(cash * 100)

# quarters

total = math.floor(cashLeft / quarters)
cashLeft = cashLeft - (total * quarters)

# dimes

total = total + math.floor(((cashLeft % quarters) / dimes))
cashLeft = cashLeft - (math.floor(((cashLeft % quarters) / dimes)) * dimes)

# nickels

total = total + math.floor((cashLeft % dimes) / nickels)
cashLeft = cashLeft - (math.floor(((cashLeft % dimes) / nickels)) * nickels)

# pennies

total = total + math.floor(cashLeft % nickels)

print(total)