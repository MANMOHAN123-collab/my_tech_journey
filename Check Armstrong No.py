def Armstrong(n):
    p=n
    count=0
    while p>0:
        count+=1
        p=p//10
    sum=0
    t=n
    while t>0:
        r=t%10
        sum=sum+r**count
        t=t//10
    if sum==n:
        print("Yes: It is a Armstrong no")
    else:
        print("NO: it is not a Armstrong no")
n=int(input("Enter a no.:"))
Armstrong(n)
