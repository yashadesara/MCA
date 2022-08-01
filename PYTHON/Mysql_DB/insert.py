import mysql.connector


def insert_record(id, name, city):

    conn = mysql.connector.connect(host='localhost', user='root', password='', database='bsrdb')
    cursor = conn.cursor()
    str = "insert into add_book values('%d','%s','%s');"
    args = (id, name, city)

    try:
        cursor.execute(str % args)
        conn.commit()
        print("inserted 1 row")
    except:
        conn.rollaback()
    finally:
        cursor.close()
        conn.close()

id = int(input("enter id: "))
name = input("enter name: ")
city = input("enter city: ")

insert_record(id,name,city)