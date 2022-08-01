import mysql.connector

global conn, cursor
conn = mysql.connector.connect(
    host='localhost', user='root', password='', database='bsrdb')
cursor = cursor = conn.cursor()


def create_table():
    try:
        conn
        cursor
        cursor.execute(
            "create or replace table add_book(id int(3), name varchar(20), city varchar(20))")
        print("table created succefully")
    except:
        conn.rollback()


def insert_record(id, name, city):
    conn
    cursor
    str = "insert into add_book values('%d','%s','%s');"
    args = (id, name, city)

    try:
        cursor.execute(str % args)
        conn.commit()
        print("inserted 1 row")
    except:
        conn.rollback()


def update_record(id, name):
    conn
    cursor
    str = "update add_book set name='%s'where id='%d'"
    args = (name, id)
    try:
        cursor.execute(str % args)
        conn.commit()
        print("1 row updated")
    except:
        conn.rollback()


def delete_record(id):
    conn
    cursor
    str = "delete from add_book where id='%d'"
    args = (id)
    try:
        cursor.execute(str % args)
        conn.commit()
        print("1 row deleted")
    except:
        conn.rollback()


def select_all():
    conn
    cursor
    cursor.execute("select * from add_book")
    rows = cursor.fetchall()
    print(type(rows), rows)
    print("Total rows: ", cursor.rowcount)
    for row in rows:
        print(row[0], row[1], row[2])


print('1.create table')
print('2.insert in table')
print('3.update table')
print('4.delete table')
print('5.select all')
print('6.exit')

while True:
    choice = input("enter choice(1/2/3/4/5/6): ")

    if choice == '1':
        create_table()

    if choice == '2':
        id = int(input("enter id: "))
        name = input("enter name: ")
        city = input("enter city: ")
        insert_record(id, name, city)

    if choice == '3':
        id = int(input("enter id: "))
        name = input("enter name: ")
        update_record(id, name)

    if choice == '4':
        id = int(input("enter id: "))
        delete_record(id)

    if choice == '5':
        select_all()

    if choice == '6':
        break

    ans = input("\n want to continue ? y/n:")
    if ans == "n":
        cursor.close()
        conn.close()
        break
