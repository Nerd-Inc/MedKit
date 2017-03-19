#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unistd.h>
#include <string>
#include <typeinfo>
#include <fstream>
using namespace std;

namespace tools {
	vector<string> read_file(string), seperate(string, char);
	vector<vector<string>> read_dir(string);
	bool kill(string), check_file(string);
	template<class T> void show(T);
	void show(vector<string>);
	string remove_space(string), pipe_terminal(string);
}

string tools::pipe_terminal(string command) {
	string data;
	FILE * stream;
	const int max_buffer = 1024;
	char buffer[max_buffer];
	command.append(" 2>&1");

	stream = popen(command.c_str(), "r");
	if (stream) {
		while (!feof(stream)) if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}
	return data;
}


bool tools::check_file(string filename) {
	ifstream readfile(filename.c_str());
	if(readfile.good()) return true;

	return false;
}

vector<vector<string>> tools::read_dir(string dirname) {

	string command = "ls " + dirname;
	//cout << "command: " << command << endl;
	string files = tools::pipe_terminal(command);
	//cout << "FILES: " << files << endl;
	vector<string> hold = seperate(files, '\n');
	//for(auto i: hold) cout << "...> " << i << endl;

	vector<vector<string>> ret;
	for(auto i: hold) ret.push_back(tools::read_file(dirname + "/" + i));

	return ret;
}

//template -> string, vector
vector<string> tools::read_file(string filename) {
	ifstream readfile(filename.c_str());
	string temp;
	vector<string> file;
	
	while(getline(readfile, temp)) file.push_back(temp);
	readfile.close();
	
	return file;
}

bool tools::kill(string process_name) {
	cout << "KILLING " + process_name << endl;
	string command = "ps s > tmp_file.txt";
	system(command.c_str());
	
	vector<string> processes = tools::read_file("tmp_file.txt");
	//processes.size() == 0 ? cout << "Process not running!!" << endl : cout << "Found processes" << endl;
	
	//for(auto i: processes) cout << i << endl;
	
	//cout << "Beginning loop!" << endl;
	for(auto i: processes) {
		if(i.find(process_name)!=string::npos) {
			//cout << "process found!" << endl;
			vector<string> hold = seperate(i, ' ');
			
			/*for(unsigned int i=0;i<hold.size();i++) {
				cout << hold[i] << "-->" << i << endl;	
			}
			
			cout << seperate(i, ' ')[6] << endl; */
			//cout << "killing pid: " << seperate(i, ' ')[6] << endl;
			command = "kill -9 " + seperate(i, ' ')[6];
			
			system(command.c_str());
			
			cout << "Process killed!" << endl;
			return true;
		}
	}
	
	cout << "Process could not be killed!" << endl;
}

vector<string> tools::seperate(string input, char del) {
	vector<string> ret;
	
	while(input.find(del)!=string::npos) {
		ret.push_back(input.substr(0, input.find(del)));
		input.erase(0, input.find(del)+1);
	} if(!input.empty()) ret.push_back(input);
	
	//for(auto i: ret) cout << i << endl;
	
	return ret;
}

template<class T> void tools::show(T data) {

	//still completely under construction
	if(typeid(T).name() == typeid(int).name()) cout << data << endl;
	else if(typeid(T).name() == typeid(string).name()) cout << data << endl;
	else if(typeid(T).name() == typeid(vector<T>).name()) {
		if(typeid(T).name() == typeid(vector<string>).name()) { //useless... previous line is same thing
			vector<string> hold = data;
			for(auto i: hold) cout << i << endl;
		}
	}
}

void tools::show(vector<string> input) {
	for(auto i: input) cout << i << endl;
}

string tools::remove_space(string data) {
	if(data.find(' ')!=string::npos) {
		data.erase(0, data.find(' ')+1);
	}
	return data;
}

#endif