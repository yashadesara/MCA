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
driver.get("https://accounts.lambdatest.com/register")

time.sleep(3)
driver.find_element(By.XPATH, "//*[@data-testid='name']").send_keys("bhuro")

time.sleep(3)
driver.find_element(
    By.XPATH, "//*[@placeholder='Business Email*']").send_keys("bhuro@g.com")

time.sleep(3)
driver.find_element(
    By.XPATH, "//*[@placeholder='Desired Password*']").send_keys("123bhuro")

time.sleep(3)
driver.find_element(By.XPATH, "//*[@id='country_code']/option[89]").click()

time.sleep(3)
driver.find_element(
    By.XPATH, "//*[@placeholder='Phone*']").send_keys("1111111111")

time.sleep(3)
driver.find_element(
    By.XPATH, "//*[@id='app']/div[1]/div[2]/div[2]/div/div/div/form/div[5]/label/samp").click()

time.sleep(3)
driver.find_element(By.XPATH, "//*[@type='submit']").click()

time.sleep(3)

print("done")
