import unittest
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
import time


class GoogleTestCase(unittest.TestCase):
    def setUp(self):
        self.browser = webdriver.Chrome()
        self.browser.maximize_window()
        self.addCleanup(self.browser.quit)

    def testPageTitle(self):
        self.browser.get ('https://www.google.com')
        time.sleep(3)
        self.assertIn('Google',self.browser.title)
    
    def testSearchPageTitle(self):
        self.browser.get ('https://www.google.com')
        self.assertIn('Google',self.browser.title)
        element = self.browser.find_element(By.NAME,'q')
        assert element is not None
        element.send_keys('vs code'+Keys.RETURN)
        assert self.browser.title.startswith('vs code')

if __name__ == '__main__':
    unittest.main(verbosity=2)



