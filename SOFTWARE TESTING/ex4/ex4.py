from selenium import webdriver
from selenium.webdriver.chrome.service import Service

driver=webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()
# driver.get("https://www.google.com")
driver.get("https://www.tutorialspoint.com/questions/index.php")
print(driver.title)
print(driver.current_url)
print(driver.page_source)
driver.close()

