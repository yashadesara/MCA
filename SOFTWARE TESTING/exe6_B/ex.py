from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.alert import Alert
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://efixman.com//customer/register")

# n = driver.find_element(By.NAME,'customerName')
# n.send_keys("Demo4030")

# e = driver.find_element(By.NAME,'customerEmail')
# e.send_keys("mokame9731@dmosoft.com")

# p = driver.find_element(By.NAME,'customerPassword')
# p.send_keys("1234harrybhai")

# mn = driver.find_element(By.NAME,'customerMobileNumber')
# mn.send_keys("9898989898")

# print(n.get_attribute("value"))
# print(e.get_attribute("value"))
# print(p.get_attribute("value"))
# print(mn.get_attribute("value"))

# c = driver.find_element(By.XPATH,"//button[1]")
# c.click()
# time.sleep(3)
# driver.switch_to.alert.accept()
# print("Registered")

l = driver.find_element(By.LINK_TEXT,'Login')
l.click()

n2 = driver.find_element(By.XPATH,"//div[1]/input[1]")
n2.send_keys("mokame9731@dmosoft.com")

n2 = driver.find_element(By.XPATH,"//div[2]/input[1]")
n2.send_keys("1234harrybhai")

cl = driver.find_element(By.XPATH,"//button[1]")
cl.click()

co = driver.find_element(By.LINK_TEXT,'Logout')
co.click()

cl.sleep(3)
driver.close()







