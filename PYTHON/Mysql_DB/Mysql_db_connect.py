import mysql.connector
from mysql.connector import Error

def connect():
    # print(__name__)
    conn = None
    try:
        conn = mysql.connector.connect(
            host='localhost', user='root', password='', database='test')
        if conn.is_connected():
            print("connected to Mysql DB")
            print(conn)
    except Error as e:
        print(e)
    finally:
        if conn is not None and conn.is_connected():
            conn.close()


if __name__ == '__main__':
    connect()
