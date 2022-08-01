import mysql.connector

def create_table():
    try:
        conn = mysql.connector.connect(host='localhost', user='root', password='', database='bsrdb')
        cursor = conn.cursor()
        cursor.execute("create or replace table add_book(id int(3), name varchar(20), city varchar(20))")
        print("table created succefully")
    except:
        conn.rollback()
    finally:
        cursor.close()
        conn.close()

create_table()