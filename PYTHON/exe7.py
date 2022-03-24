# 7 Write a Python program to check if the number provided by the user is an Armstrong number

a = int(input("enter number: "))
sum=0
temp=a
while temp>0:
    digit = temp%10
    sum = sum+(digit**len(str(a)))
    temp = temp//10

if a == sum:
    print(f"{a} is armstrong")
else:
    print(f"{a} is not armstrong")


# list comprehension

# lst = sum([int(x)**len(str(a)) for x in str(a)])
# if(a==lst):
#     print(f"{a} is armstrong")
# else:
#     print(f"{a} is not armstrong")


