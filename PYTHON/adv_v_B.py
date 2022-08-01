import re
from turtle import st

str = "this hi is test 88 string"

res = re.findall(r'\S\w\S',str)
res = re.findall(r'\b\w{4}\b',str) #get 4 char words
res = re.findall(r'\d{2}',str) #get 88

print(res)