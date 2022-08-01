from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.maximize_window()
driver.get("https://www.geeksforgeeks.org/")

# driver.set_page_load_timeout(30)
element = WebDriverWait(driver, 10).until(EC.presence_of_element_located((
    By.LINK_TEXT,"Courses")))

element.click()
driver.close()




