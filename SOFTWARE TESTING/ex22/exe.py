from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
import time

username = input("enter username: ")
password = input("enter password: ")
# user = "pandyaharry777@gmail.com"
# pass = "Harry@786$"

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()

driver.get('https://github.com/login')

element1 = driver.find_element(By.NAME, 'login')
element1.send_keys(username)

element2 = driver.find_element(By.NAME, 'password')
element2.send_keys(password)

driver.find_element(By.NAME, 'commit').click()
#for logout
# driver.find_element(By.XPATH, "//*[@class='details-overlay details-reset js-feature-preview-indicator-container']").click()
# driver.find_element(By.XPATH, "//button[contains(@class, 'dropdown-signout')]").click()

time.sleep(5)

WebDriverWait(driver=driver, timeout=10).until(lambda x: x.execute_script("return document.readyState==='complete'"))

error_msg = "incorrect user or pass"
errors = driver.find_elements(By.CLASS_NAME, 'flash-error')


for e in errors:
    print(e.text)


if any(error_msg in e.text for e in errors):
    print("login failed")
else:
    print("login success")


time.sleep(3)
driver.quit()
