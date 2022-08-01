# for i in range(1,11):
#     print(i)


# s = "jvims"
# for i in s:
#     print(i)



# j2 = [1,2,3]
# j = {'hello':'world','hello2':'world2'}
# for i in j:
#     print(type(j2))



# i = int(input("enter a: "))
# if i<18:
#     print("not done")
# else:
#     print("done")



# class data:
#     def hello(a,b):
#         return a+b

# print(data.hello(1,2))



# def fun(n):
#     for i in n:
#         print(i)

# data = [x for x in input().split(' ')]
# print(data)
# fun(data)


# try:
#     x=10
#     assert x>=5 and x<=10
#     print("no is: ",x)
# except AssertionError:
#     print("not allowed")


# try:
#     x=1
#     assert x>=5 and x<=10, "not allowed"
#     print("no is: ",x)
# except AssertionError as a:
#     print(a)

# class MyError(Exception):
#     def __init__(self,value):
#         self.value=value
#     def __str__(self):
#         return (repr(self.value))

# try:
#     raise(MyError(2*2))
# except MyError as e:
#     print("user defined exception ",e)



# class MyError(Exception):
#     def __init__(self,value):
#         self.value=value
#     def __str__(self):
#         return (repr(self.value))

# try:
#     i=1
#     if i>=5 and i<=10:
#         print("done")
#     else:
#         raise(MyError("not allowed"))

# except MyError as e:
#     print("user defined exception ",e)


# class My():
#     def __init__(self,fn,mn,ln):
#         self.fn=fn
#         self.mn=mn
#         self.ln=ln
#     def __str__(self):
#         return (self.fn+" "+self.mn+" "+self.ln)

# o = My("A","B","C")
# print(o)

class Employee():
    def __init__(self,id,name):
        self.id=id
        self.name=name

    
       
