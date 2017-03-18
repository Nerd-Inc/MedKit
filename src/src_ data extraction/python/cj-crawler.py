import requests
from bs4 import BeautifulSoup

def medspider(url):
        #creating storage file
        file_name = r"crawler.txt"
        access_mode = 'w+'
        myfile = open(file_name, access_mode)
        #url = "http://symptoms.webmd.com/#introView"

        source_html = requests.get(url)
        plain_html = source_html.text
        soup = BeautifulSoup(plain_html, "html.parser")
        for link in soup.findAll('a'):
		print(url + ": " + str(link.get("href")))
		href = str(link.get("href"))
		links = str(href)
		element_content = link.string
		print(href)
		print(element_content)
		# get_single_item(href)
		myfile.write(links +"\n")
        myfile.close()


def get_single_item(item_url):
    source_html = requests.get(item_url)
    plain_html = source_html.text
    soup = BeautifulSoup(plain_html, "html.parser")
    for item_name in soup.findAll('a'):
        this_link =item_url + item_name.get("href")

    print(this_link)
#while True:
#try:
if __name__ == "__main__":
	#url_name = input("please enter the full url you want to crawl (eg https://google.com): " )
	url_name = "http://symptomchecker.webmd.com";
	medspider(url_name)
	count = input("do you want to try again(y/n): ").upper()

	print("thanks for using this web crawler")
	





