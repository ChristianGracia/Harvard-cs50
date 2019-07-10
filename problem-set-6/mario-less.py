i = 0
while i < 1:
    userheight = input("height:")
    
    if userheight.isalpha():
        i = 0
    elif userheight.isdigit():
        height = int(userheight)
    
        if height > 0:
            if height < 9:
                i = 1
            else:
                i = 0
        else:
            i = 0

counter = height
hashes = 1
spaces = height-1

for x in range(0, height):
    while (counter > 0):
        print((" "*spaces)+("#"*hashes))
        spaces = spaces-1
        hashes = hashes + 1
        counter = counter-1
