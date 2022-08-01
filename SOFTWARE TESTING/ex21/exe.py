from xml.dom.minidom import Element
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()

driver.get('https://www.python.org')

print(driver.title)
assert "Python" in driver.title

element = driver.find_element(By.NAME,'q')
element.clear()
element.send_keys("pypi")
element.send_keys(Keys.RETURN)
assert "No results found." not in driver.page_source

time.sleep(5)

driver.quit()
