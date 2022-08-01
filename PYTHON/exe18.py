# Write a program to read CSV file and generate output using HTML table. 

import pandas as pd
filepath = "data2.csv"
df = pd.read_csv(filepath)

df.to_html("empdata.html")
print(df.to_json("emp.json"))
print(df)