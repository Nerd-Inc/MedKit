import requests
from bs4 import BeautifulSoup

def medspider(URL_LINK):
	url = URL_LINK
	source_html = requests.get(url)
	plain_html = source_html.text
	soup = BeautifulSoup(plain_html, "html.parser")
	for link in soup.findAll('a'):
		href = str(link.get("href"))
		if href[0] == 'h':
			medspider.count += 1
			print(str(medspider.count) + ": " + href)


medspider.count = 0
medspider("http://symptomchecker.webmd.com")
