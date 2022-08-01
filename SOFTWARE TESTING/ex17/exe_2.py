from selenium.webdriver.support.ui import Select
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.selenium.dev/selenium/docs/api/java/overview-summary.html")

driver.find_element(By.XPATH, "//div[1]/div[2]/ul[1]/li[1]/a[1]").click()
time.sleep(5)
driver.switch_to.frame("packageListFrame")

driver.find_element(By.LINK_TEXT, "org.openqa.selenium.opera").click()
time.sleep(5)

driver.switch_to.default_content()

driver.switch_to.frame('packageFrame')

driver.find_element(By.LINK_TEXT, "OperaOptions").click()
time.sleep(5)

driver.switch_to.default_content()

driver.switch_to.frame('classFrame')
time.sleep(5)

driver.find_element(
    By.XPATH, "/html/body/header/nav/div[1]/div[1]/ul/li[5]/a").click()
time.sleep(5)

driver.close()
