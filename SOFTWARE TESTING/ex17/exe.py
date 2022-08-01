from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://the-internet.herokuapp.com/")

driver.refresh()

driver.find_element(By.LINK_TEXT, 'Frames').click()
time.sleep(5)

driver.find_element(By.LINK_TEXT, 'Nested Frames').click()
time.sleep(5)

driver.switch_to.frame("frame-bottom")
time.sleep(5)

driver.switch_to.default_content()

driver.close()
