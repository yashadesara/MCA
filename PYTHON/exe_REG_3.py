import re

str = "1001 bhuro bhai 4564667890 11-12-2022"

result = re.search(r'\d+',str)
print(result.group())

result = re.search(r'[a-zA-Z]\D+',str)
print(result.group())

result = re.search(r'\d{10}',str)
print(result.group())

result = re.search(r'\d{1,2}-\d{1,2}-\d{2,4}',str)
print(result.group())