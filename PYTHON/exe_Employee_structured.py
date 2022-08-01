from exe_Employee import *

basic = float(input("enter baisc salary: "))
gross = basic+da(basic)+hra(basic)

print("your gross salry is: {:10.2f}".format(gross))

net = gross-pf(basic)-itax(gross)

print("your net salry is: {:10.2f}".format(net))