from selenium.webdriver.support.select import Select
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.refresh()
driver.maximize_window()
driver.get("https://www.google.com")
driver.get("https://www.gmail.com")

driver.back()
print(driver.title)
time.sleep()

driver.forward()
print(driver.title)
time.sleep()

driver.close()

