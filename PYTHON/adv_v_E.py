import re
from turtle import st

str = "22 West Westin st., South Carolina,12345 22 West Westin street, SC, 1235 123 S. Vancouver ave. in Ottawa 123 S. Vancouver avenue in OttawaThis was written in 1999 in Montreal,420 Funny Lane, Cupertino CA, 12321 Mammoth Lane, Lexigton Ma 77777"
res = re.findall(r'\d{1,4} [A-z|a-m]* \w+[.|,]', str)

print(res)
