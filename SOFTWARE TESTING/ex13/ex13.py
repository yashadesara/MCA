from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com")
# driver.get("https://www.tutorialspoint.com/index.htm")

c = {'name':'c1','value':'val1'}
driver.add_cookie(c)

l = driver.get_cookie('c1')
print('cookie is: ',l)

m = driver.get_cookies()
print('cookie is: ',m)

driver.delete_cookie('c1')
l = driver.get_cookie('c1')
print('cookie is: ',l)
driver.close()


