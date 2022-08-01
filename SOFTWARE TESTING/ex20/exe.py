from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()

driver.get('https://the-internet.herokuapp.com/jqueryui/menu')

a = ActionChains(driver)
ele = driver.find_element(By.LINK_TEXT, 'Enabled')
a.move_to_element(ele).perform()
ele2 = driver.find_element(By.LINK_TEXT, 'Back to JQuery UI')

a.move_to_element(ele2).click().perform()

print(driver.title)

time.sleep(3)

driver.quit()
