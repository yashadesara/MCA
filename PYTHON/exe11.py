# 11 Write a program in python to implement Fibonacci series up to user entered number.
# (Use recursive Function)

a = int(input("enter no: "))
def fibo(n):
    if n<=1:
        return n
    else:
        return (fibo(n-1)+fibo(n-2)) 

if a<=0:
    print("enter positive number")
else:
    for i in range(a):
        print(fibo(i), end='')
