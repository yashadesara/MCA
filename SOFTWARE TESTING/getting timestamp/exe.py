from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from time import gmtime, strftime, localtime
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com/")

driver.find_element(By.NAME, 'q').send_keys("vs code{}".format(strftime("%d-%m-%Y %H:%M:%S", localtime())))

time.sleep(5)
driver.close()
