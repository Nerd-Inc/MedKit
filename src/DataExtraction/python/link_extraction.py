import string
letters = list(list(string.ascii_lowercase))
# http://www.medicinenet.com/symptoms_and_signs/alpha_e.htm

# generating url links on disease list
def url_links(max_page = 25):
    #file name
    first_extraction = open("first_url_list.txt","w+")
    first_page = 0
#looping on letters to derived specified url
    print("List of alpha links")
    url_list = list()
    while first_page <= max_page:
        url = "http://www.medicinenet.com/symptoms_and_signs/alpha_" + letters[first_page] +".htm"
        url_list.append(url)
        #saving to file
        first_extraction.write(url + "\n")

        print(url)
        first_page +=1
    # returnning a list of uls for further use
    first_extraction.close()
    return url_list