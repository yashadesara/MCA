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
driver.get("http://demo.automationtesting.in/Register.html")


driver.find_element(By.XPATH, "//*[@placeholder='First Name']").send_keys("bhuro")
time.sleep(1)

driver.find_element(By.XPATH, "//*[@placeholder='Last Name']").send_keys("bhai")
time.sleep(1)

driver.find_element(By.XPATH, "//*[@ng-model='Adress']").send_keys("Dubai city,jamnagar")
time.sleep(1)

driver.find_element(By.XPATH, "//*[@ng-model='EmailAdress']").send_keys("bhuro@g.com")
time.sleep(1)

driver.find_element(By.XPATH, "//*[@ng-model='Phone']").send_keys("9999999999")
time.sleep(1)

driver.find_element(By.XPATH, "//*[@value='Male']").click()
time.sleep(1)


driver.find_element(By.XPATH, "//*[@value='Cricket']").click()
time.sleep(1)

driver.find_element(By.XPATH, "//*[@value='Movies']").click()
time.sleep(1)

driver.find_element(By.LINK_TEXT,'English').click()
time.sleep(1)

driver.find_element(By.XPATH,"//*[@value='CSS']").click()
time.sleep(1)















