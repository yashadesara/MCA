# Write a program in python to implement Railway Reservation System using file
# handling technique. System should perform below operations.
# a. Reserve a ticket for a passenger.
# b. List information all reservations done for today’s trains.

import csv
import os
import datetime

class Railway:
    def reserve(self,_from,_to,_person):
        row = [_from,_to,datetime.date.today(),_person]
        with open("tick.csv",mode='a',newline='\n',encoding='utf-8') as csv_file:
            writer = csv.writer(csv_file)
            writer.writerow(row)

    def showTodayRecords(self):
        with open("tick.csv",mode='r') as csv_file:
            data = list(csv.DictReader(csv_file))
            for row in data:
                if str(datetime.date.today()) == row["Date"]:
                    print(row["_person"], "has booked", "from", row["_from"],"to",row["_to"],"on",row["Date"])


def main():
    railway = Railway()
    clear = lambda:os.system('cls')

    while True:
        clear()
        print("\n1. display todays reserved tickets")
        print("2. reserve a ticket")
        print("3. exit")

        choice = input("\nenter a choice:")

        if choice=='1':
            railway.showTodayRecords()
        elif choice=='2':
            _from = input("from: ")
            _to = input("to: ")
            _person = input("person: ")
            railway.reserve(_from,_to,_person)
        elif choice=='3':
            break

        ans = input("\n want to continue y/n:")
        if ans=='n':
            break

main()
           

