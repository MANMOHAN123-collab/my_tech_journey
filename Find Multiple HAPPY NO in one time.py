def happy(num):
    
    while num!=1 and num!=4:
        sum=0
        while num>0:
            r=num%10
            sum=sum+r*r
            num//=10
        num=sum
    return num==1
list=[]
p=int(input("Enter counting of no.:"))
for i in range(p):
    q=int(input("Enter a no.:"))
    list.append(q)
print("happy no are:")
for z in list:
    if happy(z):
        print(z,end=" ")
    file=open("pkk.txt","w")
    file.write(str(z))
    file.close()






    
