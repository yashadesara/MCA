from tkinter import *
import mysql.connector

root = Tk()


def retrive_rows(id):
    conn = mysql.connector.connect(
        host='localhost', user='root', password='', database='bsrdb')
    cursor = conn.cursor()
    str = "select * from add_book where id=%d"
    args = (id)

    cursor.execute(str % args)
    row = cursor.fetchone()
    if row is not None:
        lbl = Label(text=row, font=('Arial', 14)).place(x=50, y=200)
    cursor.close()
    conn.close()


def display(self):
    str = el.get()
    lbl = Label(text="You Entered: ", font=('Arial', 35)).place(x=50, y=150)
    retrive_rows(int(str))


f = Frame(root, height=350, width=600)
f.propagate(1)
f.pack()
l1 = Label(text="Enter id: ", font=('Arial', 14))

el = Entry(f, width=15, fg="blue", bg="yellow", font=('Arial', 14))
el.bind("<Return>", display)
l1.place(x=50, y=100)
el.place(x=300, y=100)
root.mainloop()
