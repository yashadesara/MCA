from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()

driver.get("http://demo.automationtesting.in/Windows.html")

driver.find_element(By.XPATH,"//*[@id='Tabbed']/a/button[1]").click()

h = driver.window_handles
for i in h:
    driver.switch_to.window(i)
    print(driver.title)

driver.quit()
