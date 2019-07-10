import cs50

cash = 0

while cash == 0:
   temp = cs50.get_float("Change owed: ")
   
   if temp > 0:
       cash = temp
       print(cash)
   else:
        cash = 0


pennies = .01
nickels = .05
dimes = .10
quarters = .25
total = 0


total = total + (cash % quarters)

print(total)