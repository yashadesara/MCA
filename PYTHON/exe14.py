# Write a program in python to implement Salary printing file read operation. (File 
# format:
# Employee No, name, deptno, basic, DA, HRA, Conveyance) should perform below 
# operations.
# a) Print Salary Slip for given Employee Number
# b) Print Employee List for Given Department Number


import csv
import os
from pickle import FALSE

class EMP:
    def __init__(self):
        with open('data.csv',mode='r') as csv_file:
            self.data = list(csv.DictReader(csv_file))

    
    def printSalarySlip(self,empId):
        for row in self.data:
            if row['empno'] == empId:
                print("\empno %s" % row['empno'])
                print("name: %s" % row["name"])
                salary = int(row["basic"]) + int(row["DA"]) +  int(row["HRA"]) +  int(row["conv"])
                print("salary is: %s" % salary)


    def printEmpByDept(self,deptno):
        flag = False
        for row in self.data:
            if row['deptno'] == deptno:
                if flag==False:
                    print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format("empno", "name","deptno","basic","DA","HRA","conv"))
                    flag=True

                print("{:<10} {:<10} {:<10} {:<10} {:<10} {:<10} {:<10}".format(row['empno'],row['name'],row['deptno'],row['basic'],row['DA'],row['HRA'],row['conv']))
            
            if flag==False:
                print("\n no emp found on deptno: %s" % deptno)        

obj = EMP()

while True:
    clear = lambda: os.system('cls')
    clear()

    print("\n 1. print salary slip")        
    print("2. print emp by dept no")        
    print("3. exit")        
    choice = input("\n enter choices: ")

    if choice == "1":
        empNo = input("\n enter emp no: ")
        obj.printSalarySlip(empNo)

    if choice == "2":
        empNo = input("\n enter dept no: ")
        obj.printEmpByDept(empNo)

    if choice == "3":
        break
    ans = input("\n\n want to continue ? y/n:")
    if ans=="n":
        break



    
