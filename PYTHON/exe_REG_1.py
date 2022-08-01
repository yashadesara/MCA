import re

str = "sun men lop run manmohan"
str2 = "this: is the:'core' python's book"

# res = re.search('m\w\w',str)
res = re.split(r'\W+', str2)

print(res)

res = re.split(r':', str2)
res = re.sub(r'core', 'advanced', str2)
print(re.sub(r'[a,e,i,o,u]', 'X', str2))

# res = re.match(r's\w\w', str)
# res = re.findall(r'm\w\w', str)

print(res)

# if res:
#     print(res.group())
#     print(res.span())
#     print(res.string)
