<center> <h1> MedKit </h1> </center>

![MedKit](userinterface/images/MedKit2.0.png)

## File Structure

| Directory Name | Content |
|----------------|----------------|
| [src/](https://github.com/Nerd-Inc/MedKit/src) | Data Tools |
| [src/DataExtraction/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction) | Data Extraction tools |
| [src/DataExtraction/cpp/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/cpp) | Data Analyser |
| [src/DataExtraction/cpp/compressor/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/cpp/compressor) | Data compressor |
| [src/DataExtraction/cpp/symptoms_syntax_finder/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/cpp/symptoms_syntax_finder) | Data analysis tools and classifier |
| [src/DataExtraction/cpp/symptoms_syntax_finder/database/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/cpp/symptoms_syntax_finder/database) | Parsed data files |
| [src/DataExtraction/cpp/symptoms_syntax_finder/DataFiles/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/cpp/symptoms_syntax_finder/DataFiles) | Raw unparsed data |
| [src/DataExtraction/javascript/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/javascript) | Symptoms crawler |
| [src/DataExtraction/python/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/python) | Data links extractor |
| [src/DataExtraction/shell/](https://github.com/Nerd-Inc/MedKit/src/DataExtraction/shell) | Data extractor |
|      |      |
| [userinterface/](https://github.com/Nerd-Inc/MedKit/userinterface) | User interface |
| [userinterface/images/](https://github.com/Nerd-Inc/MedKit/userinterface/images) | All images go here  |
| [userinterface/javascript-ui/](https://github.com/Nerd-Inc/MedKit/userinterface/javascript-ui) | Scripts for UI |
| [userinterface/pages/](https://github.com/Nerd-Inc/MedKit/userinterface/pages) | UI pages |
| [userinterface/scss](https://github.com/Nerd-Inc/MedKit/userinterface/scss) | Precompiled CSS |
| [userinterface/stylesheet](https://github.com/Nerd-Inc/MedKit/userinterface/stylesheet) | Compiled CSS |

## Run Application

#### Install Node.js, Node Package Manager and Electron
```shell
	$ sudo apt update
	$ sudo apt install nodejs
	$ sudo apt install npm
	$ sudo npm install -g electron
```
#### Clone the repository
```shell
	$ git clone https://github.com/Nerd-Inc/MedKit.git/
	$ cd MedKit
	$ npm start
```
## Want to Contribute?

All contributions are welcomed and highly appreciated. If you will like to be a contributor to this project, take a few minutes to read the [__Code of Conduct__](https://github.com/Nerd-Inc/MedKit/blob/master/code_of_conduct.md). Also, you should configure your code editor/IDE to use 4 tabs of indention. Variables names should be descriptive and should be follow the code style of the language. Example:

JavaScript
```javascript

   var additionInClosure = function (argumentOne){
	   // function name should tell what the function does
	   // variable names are camel case
	   return function (argumentTwo){
		   return console.log(argumentOne + argumentTwo);
	   }
   }
```
C++
```cpp
   void read_and_show_content_of_file(string filename) {
		ifstream read_file(filename.c_str());
		std::string file_line;
		// variable name should be descriptive and word delimiter is an underscore
		while(getline(read_file, file_line)){
			std::cout << file_line << std::endl;
		}
	}
```
