# 2 Write a program in python to swap two variables without using temporary variable.

a = int(input("enter a: "))
b = int(input("enter a: "))

print(a,b)
a,b = b,a
print(a,b)