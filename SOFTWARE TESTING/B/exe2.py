from email.mime import image
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from PIL import Image
import time

print("case started")

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
# driver=webdriver.Firefox(service=Service("geckodriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com")

driver.save_screenshot("Image.png")
image = Image.open("Image.png")
image.show()
time.sleep(3)
driver.close()


