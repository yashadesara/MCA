from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.google.com")

# driver.get("https://github.com/login")
# driver.find_element(By.NAME,"login").send_keys("this is good")
# driver.find_element(By.NAME,"password").send_keys("hi there")
# driver.find_element(By.NAME,"commit").submit()
# driver.find_element(By.XPATH,"//*[@development='false']").submit()
# element = driver.find_element(By.XPATH,"//*[@data-pid='23']")
l = driver.find_element(By.XPATH,"//*[@title='Search']")

# action = ActionChains(driver)
# action.key_down(Keys.CONTROL).click(element).key_up(Keys.CONTROL).perform()
# action.key_down(Keys.SHIFT).click(element).key_up(Keys.SHIFT).perform()

l.send_keys("vs code")
l.send_keys(Keys.RETURN)
driver.close()


