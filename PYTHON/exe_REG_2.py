import re
str = "bana 1st bina 2nd bipin 3rd hitesh 4th bhurabhai"

print(re.findall(r'b[\w]*',str)) #starts with b and going infinity

print(re.findall(r'\d[\w]*',str)) #find digits

print(re.findall(r'\b\w{5}\b',str)) #find with specified(5) chars

print(re.findall(r'\b\w{5,}\b',str)) #find atleast 5 chars and max in infinity 

print(re.findall(r'\b\w{3,5}\b',str))  #find atleast 3 chars and max in 5

print(re.findall(r'b[\w]*\Z',str)) #find only at the last position starts with 'b'

print(re.findall(r'^b[\w]*',str)) #find only at the first position starts with 'b'
# or
print(re.findall(r'\Ab[\w]*',str)) #find only at the first position starts with 'b'


str2 = "hi anandi and ankita, h r u"

print(re.findall(r'a[nk][\w]*',str2))

print(re.search(r'^bhuro','bhuro h r u?'))

print(re.search(r'bhuro$','h r u bhuro'))

print(re.search(r'U$',str2,re.IGNORECASE))

