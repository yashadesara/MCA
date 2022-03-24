# 9 Write a Python program to perform following operation on given string input:
# a) Count Number of Vowel in given string
# b) Count Length of string (do not use Len ())
# c) Reverse string
# d) Find and replace operation
# e) check whether string entered is a palindrome or not

from dataclasses import replace


a = input("enter string: ")
c = 0
vowels = 0
vs = set("aeiouAEIOU")

# for i in a:
#     if i in vs:
#         vowels=vowels+1
# print("vowels count is: ",vowels)

vow = len([x for x in a if x in vs])
print("vowels count is: ",vow)


# for i in a:
#     c=c+1

print("count is: ",len([x for x in a]))

# print("count is: ",c)
print("reverse is: ",a[::-1])

x = a.replace("world","bro")
print(x)

if(a[::-1]==a):
    print("pelindrome")
else:
    print("not pelindrome")


