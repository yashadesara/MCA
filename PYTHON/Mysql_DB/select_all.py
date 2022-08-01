import mysql.connector


def select_all():
    conn = mysql.connector.connect(host='localhost', user='root', password='', database='bsrdb')
    cursor = conn.cursor()
    cursor.execute("select * from add_book")
    rows = cursor.fetchall()
    print(type(rows),rows)
    print("Total rows: ",cursor.rowcount)
    for row in rows:
        print(row[0],row[1],row[2])
    cursor.close()
    conn.close()

select_all()