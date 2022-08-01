from selenium.webdriver.support.select import Select
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys

from selenium.webdriver.common.alert import Alert
import time


driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://nxtgenaiacadmy.com/demo-site")




# driver.find_element(By.XPATH, "//*[@name='firstname']").send_keys("bhuro")

# driver.find_element(By.XPATH, "//*[@name='lastname']").send_keys("bhai")

# driver.find_element(By.XPATH, "//*[@value='Male']").click()

# driver.find_element(By.XPATH, "//*[@value='5']").click()

# driver.find_element(
#     By.XPATH, "//*[@id='mainContent']/div[4]/div/form/table/tbody/tr[5]/td[2]/input").send_keys("02/03/2000")

# driver.find_element(By.XPATH, "//*[@value='Automation Tester']").click()

# driver.find_element(By.XPATH, "//*[@type='file']").send_keys(
#     "C:\\Users\\Student\\Downloads\\wallpaper1.jpg")

# driver.find_element(By.XPATH, "//*[@value='Selenium IDE']").click()

# x = Select(driver.find_element(By.XPATH, "//*[@name='continents']"))
# x.select_by_index(1)

# sel = Select(driver.find_element(By.NAME, 'selenium_commands'))
# sel.select_by_index(2)
# sel.select_by_visible_text("Wait Commands")
# time.sleep(0.5)
# driver.find_element(By.XPATH, "//*[@name = 'submit']").click()

# alert = Alert(driver)
# print(alert.text)
# alert.accept()

# print("done")
