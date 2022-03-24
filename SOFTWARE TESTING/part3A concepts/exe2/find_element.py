from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time


driver=webdriver.Chrome(service=Service("./chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com")
# l = driver.find_element(By.ID, "search-strings")
# l = driver.find_element(By.NAME, "key")
# l = driver.find_element(By.TAG_NAME, "input")
# l = driver.find_element(By.CSS_SELECTOR, "input[name='q']")

#relative xpath:
# l = driver.find_element(By.XPATH, "//*[@name='key']")

#full xpath:
# l = driver.find_element(By.XPATH, "/html/body/div[1]/div[2]/div[2]/div/input")

# l = driver.find_element(By.CLASS_NAME, "gb_d")
# l = driver.find_element(By.LINK_TEXT, "Gmail")
l = driver.find_element(By.PARTIAL_LINK_TEXT, "in")
# v = l.text
l.click()
print(driver.title)

# l.send_keys('js')
# v = l.get_attribute('value')
# print("value is: "+v)
time.sleep(10)
driver.close()


