# 4 Write a program to make a simple calculator (using functions).
def add(a,b):
    return a+b

def sub(a,b):
    return a-b

def mul(a,b):
    return a*b

def div(a,b):
    return a/b

def selection(c):
    a = int(input("enter a: "))
    b = int(input("enter b: "))

    if c=='1':
        print(add(a,b))
    elif c=='2':
        print(sub(a,b))
    elif c=='3':
        print(mul(a,b))
    elif c=='4':
        print(div(a,b))
    else:
        print("invalid")
        
while(1):
    c = input("enter ch: 1)+ 2)- 3)* 4)/ 5)exit: ")
    if c == '5':
        break
    else:
        selection(c)
   
    
