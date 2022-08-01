import re
from turtle import st

str = "www.gmail.com www.yahoo.com www.gtu.orgs"

res = re.findall(r'www.\w+.\w{3}\b',str)

print(res)