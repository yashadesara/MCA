from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com")

driver.execute_script("window.open('about:blank','secondtab');")
driver.switch_to.window('secondtab')

driver.get('https://www.apple.com')
driver.execute_script("window.open('about:blank','thirdtab');")

driver.switch_to.window('thirdtab')

driver.get('https://www.gmail.com')
