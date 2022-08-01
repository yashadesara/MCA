from selenium.webdriver.chrome.options import Options
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from fake_useragent import UserAgent
import time

options = Options()
ua = UserAgent()
userAgent = ua.random
print(userAgent)
options.add_argument(f'user=-agent={userAgent}')

driver=webdriver.Chrome(options=options,service=Service("chromedriver.exe"))
driver.maximize_window()
driver.get('https://www.google.com')
time.sleep(5)
driver.close()


