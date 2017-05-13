from link_extraction import url_links
from urllib.parse import urljoin
from bs4 import BeautifulSoup
import requests
def disease_link():
    actual_links = open(r"links.txt", "w+")
    parent_url = "http://www.medicinenet.com"
    # iterating through links to get desire info
    urls = url_links()
    list_iter = iter(urls)
    # list to be used in the engine
    data_link = list()
    print('Generating absolute url')
    while True:
        try:

            next_url = next(list_iter)
            print(next_url)
            print("-" * 100)
            # using beautiful soup to extract the urls
            source_code = requests.get(next_url)
            plain_text = source_code.text
            soup = BeautifulSoup(plain_text, "html.parser")


            for link in soup.findAll('a'):

                href =str(link.get('href'))
                # house keeping here!!! trying to remove unwanted url
                if not( href.startswith("http") or  href.startswith( "/symptoms") or href.startswith("/script") or href.startswith ("#") or href.startswith("//privacy") or href.startswith("None")):
                    full_src = urljoin(parent_url, href)
                    actual_links.write(full_src + '\n')
                    data_link.append(full_src)

        except StopIteration:
            break
    return data_link

