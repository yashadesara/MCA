
import mysql.connector


def update_record(id,name):
    conn = mysql.connector.connect(host='localhost', user='root', password='', database='bsrdb')
    cursor = conn.cursor()
    str = "update add_book set name='%s'where id='%d'"
    args = (name,id)
    try:
        cursor.execute(str %args)
        conn.commit()
        print("1 row updated")
    except:
        conn.rollback()
    finally:
        cursor.close()
        conn.close()


id = int(input("enter id: "))
name = input("enter name: ")

update_record(id,name)