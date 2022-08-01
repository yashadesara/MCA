import re
import urllib.request

f = urllib.request.urlopen(r'file:///E://PYTHON//index.html')

txt = f.read()

str = txt.decode()
res = re.findall(r'<td>\w+</td>', str)
print(res)

f.close()
