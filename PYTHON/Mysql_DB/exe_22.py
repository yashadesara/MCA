from datetime import datetime
import mysql.connector
from mysql.connector import Error

global conn, cursor
conn = mysql.connector.connect(
    host='localhost', user='root', password='', database='bsrdb')
cursor = conn.cursor()


def create_table():
    try:
        conn
        cursor
        cursor.execute(
            "create or replace table tbl_event(id int(3) primary key AUTO_INCREMENT, name varchar(20), date_time varchar(20), status int(1))")
        print("table created succefully")
    except:
        conn.rollback()


def insert_record(name):
    conn
    cursor
    x = datetime.now()
    str = "insert into tbl_event (name,date_time,status) values('%s','%s','%d');"
    args = (name, f"{x.strftime('%x')} {x.strftime('%X')}", 1)

    try:
        cursor.execute(str % args)
        conn.commit()
        print("inserted 1 row")
    except Exception as e:
        print(e)
        conn.rollback()


def cancel_event(id):
    conn
    cursor
    str = "update tbl_event set status=0 where id='%d'"
    args = (id)
    try:
        cursor.execute(str % args)
        conn.commit()
        print("1 row updated")
    except:
        conn.rollback()


def update_record(id, event_name, date, status):
    conn
    cursor
    print(event_name, date, status, id)
    str = "update tbl_event set name='%s', date_time='%s', status='%d' where id='%d'"
    args = (event_name, date, status, id)
   
    cursor.execute(str % args)
    
    try:   
        conn.commit()
        print("1 row updated")
    except Exception as e:
        print(e)
        conn.rollback()


def delete_record(rec_status):
    conn
    cursor
    str = "delete from tbl_event where status='%d'"
    args = (rec_status)
    try:
        cursor.execute(str % args)
        conn.commit()
        print("1 row deleted")
    except Exception as e:
        print(e)
        conn.rollback()


def disp_data(rec_status):
    conn
    cursor
    sql = "select * from tbl_event where status='%d'"
    sql2 = "select * from tbl_event"
    if rec_status == 0:
        sql
        args = (rec_status)
        cursor.execute(sql % args)
    elif rec_status == 1:
        sql
        args = (rec_status)
        cursor.execute(sql % args)
    else:
        sql2
        cursor.execute(sql2)
    rows = cursor.fetchall()
    print("Total rows: ", cursor.rowcount)
    for row in rows:
        print(row)


print('1.create table')
print('2.add new record')
print('3.modify')
print('4.remove')
print('5.cancel event')
print('6.display all')
print('7.display regular event')
print('8.display cancel event')


while True:
    choice = input("enter choice(1/2/3/4/5/6/7/8): ")

    if choice == '1':
        create_table()

    if choice == '2':
        name = input("enter name: ")
        insert_record(name)

    if choice == '3':
        id = int(input("enter id: "))
        event_name = input("enter name: ")
        dd = int(input("enter dd: "))
        mm = int(input("enter mm: "))
        yyyy = int(input("enter yy: "))
        hh = int(input("enter hh: "))
        min = int(input("enter min: "))
        event_date = datetime(yyyy, mm, dd, hh, min, 0)
        status = int(input("enter status: "))
        update_record(id, event_name, event_date, status)

    if choice == '4':
        id = int(input("enter status: "))
        delete_record(id)

    if choice == '5':
        id = int(input("enter id: "))
        cancel_event(id)

    if choice == '6':
        status = int(input("enter status: "))
        disp_data(status)

    if choice == '7':
        status = int(input("enter status: "))
        disp_data(status)

    if choice == '8':
        status = int(input("enter status: "))
        disp_data(status)

    ans = input("\n want to continue ? y/n:")
    if ans == "n":
        cursor.close()
        conn.close()
        break
