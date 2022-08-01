from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.common.alert import Alert
import time

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
driver.get("https://www.edureka.co/")

signup = driver.find_element(By.XPATH,"//*[@class='signup_click signup-vd giTrackElementHeader ']")
signup.click()

name = driver.find_element(By.NAME,'email')
name.send_keys("lykobexa@ryteto.me")

ph = driver.find_element(By.NAME,'phone_no')
ph.send_keys("3456789011")


bt = driver.find_element(By.XPATH,"//*[@class='clik_btn_log btn-block signup-new-submit']")
bt.click()

time.sleep(10)
cp = driver.find_element(By.XPATH,"//*[@id='signup_password']").send_keys("123Harrybhai@0")

bt = driver.find_element(By.XPATH,"//*[@class='clik_btn_log btn-block sg_submit']")
bt.click()
time.sleep(5)
driver.find_element(By.XPATH,"//*[@class='webinar-profile-name']").click()
time.sleep(1)
driver.find_element(By.LINK_TEXT,"Log Out").click()
driver.close()





