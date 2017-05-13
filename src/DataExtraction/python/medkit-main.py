from disease_link import disease_link
import requests
from bs4 import BeautifulSoup

# extracting actuall links check file

# extraction engine
def data_extraction():

    data_link = disease_link()
    print("DATA EXTRACTION BEGINS HERE!!!!")
    data_file = open('data_file.txt', "w+")
    list_iter = iter(data_link)
    while True:
        try:

            next_url = next(list_iter)
            print(next_url)

            print("-" * 100)
            source_code = requests.get(next_url)
            plain_text = source_code.text
            soup = BeautifulSoup(plain_text, "html.parser")

            for disease_name in soup.find('h2'):
                print(disease_name + '+' * 50)
                data_file.write(disease_name + "*" * 50 + "\n")
            for disease_discrip in soup.findAll('p')[7] and  soup.findAll('p')[7]:
                data_str = str(disease_discrip.string)
                data_file.write(data_str)
            data_file.write("\n \n")
        except StopIteration:
            break

if __name__ == '__main__':
    data_extraction()




