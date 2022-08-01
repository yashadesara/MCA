import mysql.connector

def delete_record(id):
    conn = mysql.connector.connect(
        host='localhost', user='root', password='', database='bsrdb')
    cursor = conn.cursor()
    str = "delete from add_book where id='%d'"
    args = (id)
    try:
        cursor.execute(str % args)
        conn.commit()
        print("1 row deleted")
    except:
        conn.rollback()
    finally:
        cursor.close()
        conn.close()


id = int(input("enter id: "))
delete_record(id)
