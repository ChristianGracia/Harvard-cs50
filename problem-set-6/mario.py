i = 0
while i < 1:
    userheight = int(input("height:"))
    if userheight > 0:
        if userheight < 9:
            print ("hi")
            i = 1
        else:
            print("fail")
            i = 0
    else:
        print("fail")
        i = 0
print (userheight)
height = userheight

k=height
while (k>0):
    print( "#" +(""*k)+ "#")
    k=k-1
    
    
    
# for x in range(0, userheight):
#     for y in range (0, x):
#         print ("#") * y
    
    
    
    # print ("#")





# for x in range(0, height):
#     print ("#")

# if height > 0:
#     print('too low')
# elif 0 < height < 9:
#     print("#")
# else:
#     print('too high')

