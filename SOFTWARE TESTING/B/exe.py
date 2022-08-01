from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

import time

print("case started")

# driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver=webdriver.Edge(service=Service("msedgedriver.exe"))
# driver=webdriver.Firefox(service=Service("geckodriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com")

driver.find_element(By.NAME,'q').send_keys('vs code')
time.sleep(3)

driver.find_element(By.NAME,'btnK').send_keys(Keys.ENTER)
time.sleep(3)

driver.close()
print("case completed sucessfully")

