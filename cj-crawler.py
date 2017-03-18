import requests
from bs4 import BeautifulSoup

def medspider():

        url = "http://symptoms.webmd.com/#introView"
        source_html = requests.get(url)
        plain_html = source_html.text
        soup = BeautifulSoup(plain_html, "html.parser")
        for link in soup.findAll('a'):
            href = link.get("href")
            print(href)
medspider()

