# Write a program which will implement decorators for functions and methods in python.
# function_Decorators

def msgWithWelcome(fun):
    def addWelcome(y):
        return "hello "+fun(y)
    return addWelcome


@msgWithWelcome
def site(x):
    return x

print(site("Apple"))
