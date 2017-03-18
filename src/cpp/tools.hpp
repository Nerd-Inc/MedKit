#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

namespace tools {
	vector<string> read_file(string), seperate(string, char);
	bool kill(string);
	template<class T> void show(T);
	void show(vector<string>);
	string remove_space(string);
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
	} ret.push_back(input);
	
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