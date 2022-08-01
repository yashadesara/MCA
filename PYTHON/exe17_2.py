# Write a program which will implement decorators for functions and methods in python.
# method_Decorators

from datetime import date


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @classmethod
    def fromBirthYear(cls, name, year):
        return cls(name, date.today().year - year)

    @staticmethod
    def isAdult(age):
        return age > 18


person1 = Person('Bhuro', 20)
person2 = Person.fromBirthYear('Bhuro', 2000)
print(person1.age)
print(person2.age)

print(person1.isAdult(person1.age))
