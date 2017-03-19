#!/bin/sh

# Scrape data into text files from URLS

# Uses Lynx for text extraction
# Install lynx:  sudo apt install lynx -y
# Change mode:	 sudo chmod +x dataScraper.sh
# Execute: 		 ./dataScraper.sh

for line in `cat urls.txt`; do
	
	# Remove http://
	shortURL=`echo $line | cut -c8-`
	fileName="`echo $shortURL | sed 's/\///g'`"

	datafolder="DataFiles/"
	# Show status info
	echo "> Scraping URL: $shortURL"
	echo "> -----------------------"

	# Use Lynx to extract text
	lynx -dump -crawl -nolist "$shortURL" > $datafolder/$fileName.txt
	echo "> DONE"
	echo ""
done
