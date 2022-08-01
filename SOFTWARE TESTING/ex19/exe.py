from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException
import time

driver = webdriver.Chrome(service=Service("chromedriver.exe"))
driver.implicitly_wait(0.5)
driver.maximize_window()


def getTitleURL():
    driver.get("https://code.visualstudio.com")
    print(driver.title)
    print(driver.current_url)
    driver.quit()


def getElement():
    driver.get("https://code.visualstudio.com")
    try:
        l = driver.find_element(By.CSS_SELECTOR, 'h1')
        s = l.text
        print("element exists - "+s)
    except NoSuchElementException:
        print("element not exists")
        time.sleep(5)


def visibleText():
    driver.get("https://www.tutorialspoint.com/about/about_careers.htm")

    print("this is from full link TEXT: ", driver.find_element(
        By.XPATH, "//a[text()='Privacy Policy']").text)
    print("this is from contains link TEXT: ", driver.find_element(
        By.XPATH, "//a[contains(text(),'Privacy')]").text)


def getTableContent():
    driver.get(
        "https://www.softwaretestingmaterial.com/sample-webpage-to-automate/")
    print(len(driver.find_elements(
        By.XPATH, "//table[@class='spTable']/tbody/tr")))
    print(len(driver.find_elements(
        By.XPATH, "//table[@class='spTable']/tbody/tr/th")))

    # for printing full table
    l = driver.find_elements(By.XPATH, "//table[@class='spTable']/tbody/tr")

    # for printing header of table
    l2 = driver.find_elements(
        By.XPATH, "//table[@class='spTable']/tbody/tr/th")

    # for printing specific row of table
    l3 = driver.find_elements(
        By.XPATH, "//table[@class='spTable']/tbody/tr[2]")

    for i in l3:
        print(i.text)


if __name__ == '__main__':
    # getTitleURL()
    # getElement()
    # visibleText()
    getTableContent()
    driver.quit()
