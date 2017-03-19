import requests
from bs4 import BeautifulSoup

def medical_crawler(url, scan):
	#default url http://symptoms.webmd.com/#introView

   filename = r"urls.txt"
   mode = "w+"
   myfile = open(filename, mode)
   source_html = requests.get(url)
   plain_html = source_html.text
   soup = BeautifulSoup(plain_html, "html.parser")
   for link in soup.findAll('a',href = True):

	   href = link.get("href")
	   href = str(href)
	   # print(href)
	   if href.find("https://") is not -1 or href.find("http://") is not -1:
		  print("parent link " + str(href))
		  # print(href.find("https://") is not -1 or href.find("http://") is not -1)
		  myfile.write(str(href)+ "\n")

		  if scan == "Y":
					 #deep crawler begins here
					 source_html = requests.get(href)
					 plain_html = source_html.text
					 soup2 = BeautifulSoup(plain_html, "html.parser")
					 # print(scan)
					 for link2 in soup2.findAll("a"):
								href2 = link2.get("href")
								href2 = str(href2)

								if href2.find("https://") is not -1 or href2.find("http://") is not -1:
											   print("child link "  +  str(href2))
											   myfile.write(str(href2) + "\n")



   myfile.close()




if __name__ == "__main__":
		  # url_name = input("please enter the full url you want to crawl (eg https://google.com): " )
		  # user_url = input("please enter your full url(eg http://example.com): ")
		  print("am working on this url http://symptoms.webmd.com/#introView it is hard coded")
		  user_url =  "http://symptoms.webmd.com/#introView"
		  scan_type = input("Do you want deep scan (y/n)  warning!!! this take longer time and can contain repeated links not advicable: ").upper()
		  medical_crawler(user_url, scan_type)

		  print("thanks for using this webcrawler. you can fork this repo on this link https://github.com/Nerd-Inc/MedKit/tree/master/src/src_%20data%20extraction")
