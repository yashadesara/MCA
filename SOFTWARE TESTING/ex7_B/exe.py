from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.tutorialspoint.com/selenium/selenium_automation_practice.htm")

s = driver.find_element(By.XPATH,"//tr[7]/td[2]/input[1]")

s.send_keys("C:\\Users\Student\Downloads\wallpaper1.jpg")

time.sleep(3)
driver.close()


