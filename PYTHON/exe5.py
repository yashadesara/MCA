# 5 Write a program in python to find out maximum and minimum number out of three user entered number.

a = int(input("enter a: "))
b = int(input("enter b: "))
c = int(input("enter c: "))

if a>b and a>c:
    print(f"{a} A is big")
elif b>a and b>c:
    print(f"{b} B is big")
else:
    print(f"{c} C is big")


if a<b and a<c:
    print(f"{a} A is small")
elif b<a and b<c:
    print(f"{b} B is small")
else:
    print(f"{c} C is small")