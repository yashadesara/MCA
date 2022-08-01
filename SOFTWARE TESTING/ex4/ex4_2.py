from selenium.webdriver.support.select import Select
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://the-internet.herokuapp.com/checkboxes")

# l = driver.find_element(By.XPATH,"//tr[6]/td[2]/span[1]/input[1]")
l = driver.find_element(By.XPATH,"//input[1]")
l.click()

if l.is_selected():
    print("Checked")
else:
    print("Not Checked")
time.sleep(5)
driver.close()


