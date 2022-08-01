from selenium.webdriver.chrome.options import Options
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
import time

options = webdriver.ChromeOptions()
options.add_extension('./xpathmax.zip')

driver = webdriver.Chrome(options=options, service=Service("chromedriver.exe"))
driver.maximize_window()
driver.get('https://www.google.com')
time.sleep(5)
driver.close()
