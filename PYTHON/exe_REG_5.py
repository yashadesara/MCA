import re

f1 = open('emp.txt','r')
f2 = open('salary.txt','w')

for line in f1:
    res = re.search(r'\d{3}',line)
    res2 = re.search(r'\d{4,}.\d{2}',line)

    print(res.group(),res2.group()) 
    f2.write(res.group()+"\t")
    f2.write(res2.group()+"\n")

f1.close()
f2.close()
