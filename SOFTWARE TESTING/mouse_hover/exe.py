from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver import ActionChains
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.wikipedia.org/")

driver.execute_script("window.scrollTo(0, 500);")
# element = driver.find_element(By.XPATH,"//div[3]/div[3]/a[1]")
element = driver.find_element(By.XPATH,"//div[3]/div[5]/a[1]")

hover = ActionChains(driver).move_to_element(element)

hover.perform()
time.sleep(10)
driver.close()
