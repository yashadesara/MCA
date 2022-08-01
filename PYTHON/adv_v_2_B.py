import re

str = "888-111-333 777-222-(334)"
res = re.findall(r'\d{3}-\d{3}-[()]\d{3}[()]', str)

print(res)
