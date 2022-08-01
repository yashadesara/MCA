from selenium.webdriver.support.select import Select
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
# driver.get("https://www.google.com")
driver.get("https://www.tutorialspoint.com/selenium/selenium_automation_practice.htm")

sel = Select(driver.find_element(By.NAME,"continents"))
# sel = Select(driver.find_element(By.NAME,"selenium_commands"))

# sel.select_by_visible_text("Africa")
# sel.select_by_visible_text("Wait Commands")

driver.execute_script("window.scrollTo(0, 500);")
driver.find_element(By.ID,'banner-accept').click()

sel.select_by_index(2)
time.sleep(2)
driver.close()

# driver.get("https://github.com/login")
# driver.find_element(By.NAME,"login").send_keys("this is good")
# driver.find_element(By.NAME,"password").send_keys("hi there")
# driver.find_element(By.NAME,"commit").submit()
# driver.find_element(By.XPATH,"//*[@development='false']").submit()
# element = driver.find_element(By.XPATH,"//*[@data-pid='23']")
# l = driver.find_element(By.XPATH,"//*[@title='Search']")

# action = ActionChains(driver)
# action.key_down(Keys.CONTROL).click(element).key_up(Keys.CONTROL).perform()
# action.key_down(Keys.SHIFT).click(element).key_up(Keys.SHIFT).perform()

# l.send_keys("vs code")
# l.send_keys(Keys.RETURN)
# driver.close()


