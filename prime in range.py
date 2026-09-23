a=int(input("Enter start no.:"))
b=int(input("Enter end no.:"))
for i in range(a,b+1):
    for x in range(2,i):
        if (i%x==0):
            break
    else:
        print(i,end=" ")
        
