import re
from turtle import st

str = "bit, bat, hit, hat, hut, abc, xyz"

# res = re.findall(r'\w*, ',str)
res = re.split(r', ',str)

print(res)