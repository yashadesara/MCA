# 12 Write a program in python to implement Factorial series up to user entered number.
# (Use recursive Function)


def fact(n):
    if n<=1:
        return n
    else:
        return n*fact(n-1)

a = int(input("enter no:"))
print(fact(a))