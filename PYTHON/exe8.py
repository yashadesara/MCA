# 8 Write a Python program to check if the number provided by the user is a palindrome or not

# a = input("enter number: ")

# print(a[::-1])

# if(a==a[::-1]):
#     print("pelindrome")
# else:
#     print("not pelindrome")


a = int(input("enter number: "))
temp=a
rev=0
while(a>0):
    dig = a%10
    rev = (rev*10)+dig
    a=a//10

if(temp==rev):
    print("pelindrome")
else:
    print("not pelindrome")