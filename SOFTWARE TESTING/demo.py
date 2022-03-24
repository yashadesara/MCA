from selenium import webdriver
from selenium.webdriver.chrome.service import Service
import os

driver=webdriver.Chrome(service=Service("./chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.apple.com")
print("done")
driver.close()
