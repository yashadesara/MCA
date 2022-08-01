import re
from turtle import st

str = "abb bit bat hit hat hut abc xyz"

res = re.findall(r'\w\wt',str)
# res = re.findall(r'\w[aeiou]t',str)

print(res)