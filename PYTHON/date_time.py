import datetime

x = datetime.datetime.now()
print(type(x),x) #returns object

z = x.strftime('%X') #returns string
z2 = x.strftime('%X')
print(z)
print(z2)

if z==z2:
    print('t')
else:
    print('f')

# print(x.strftime('%x')) #date
# print(x.strftime('%X')) #time

# x = datetime.datetime(1947, 8, 15, 23, 59, 00)
# y = x.strftime('%x') #date
# print(type(y),y)

# t = x.strftime('%X') #time
# t1 = x.strftime('%X') #time

# print(type(t1),t1)
# print(type(t),t)
# print(type(z),z)

# if t1==t:
#     print("true")
# else:
#     print("false")