from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver import ActionChains
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.amazon.in/")

action = ActionChains(driver)

parent_level_menu = driver.find_element(By.XPATH,"//div[1]/a[7]/span[1]")
action.move_to_element(parent_level_menu).perform()

chile_level_menu = driver.find_element(By.XPATH,"//div[2]/div[1]/a[1]/img[1]")
chile_level_menu.click()

time.sleep(10)
# driver.close()
