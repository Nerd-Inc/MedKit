#ifndef CLASSIFIER_H_INCLUDED
#define CLASSIFIER_H_INCLUDED
#include "tools.hpp"
#define _FILE "database/symptoms/syntax/file.txt"
#define NAMES "database/symptoms/names/files.txt"
#define PARSED_DIR "DataFiles"
using namespace std;


class classifier {
    bool exe = false;
    set<string> found_matches;
    public:
    void check(), find(), relate(), question(), show();
    set<string> symptoms;
};

void classifier::check() {
    cout << "Checking file: " << _FILE << endl;
    if(tools::check_file(_FILE)) {
        cout << "\t\t[ok]" << endl;
        exe = true;
    } else cout << "\t\t[failed]" << endl;

    //more checks in file should go here
}

void classifier::find() {
    if(!exe) return;
    vector<string> file {tools::read_file(_FILE)};
    vector<vector<string>> file2 {tools::read_dir(PARSED_DIR)};
    cout << "Finding: [ RUNTIME: " << file.size() * file2.size() << "]";

    if(file.size() < 1) {
        cout << "\t\t[failed]" << endl;
        exit(1);
    }

    cout << "\tDataFiles: [" << file2.size() << "]" << endl;
    for(auto i: file2) { //vector<vector<string>>
        //cout << "in: " << i.size() << endl;
        for(unsigned int j=0;j<i.size();j++) { //vector<string>>
            //cout << "-----> " << i[j] << endl;
            cout << "Scanning..." << endl;
            for(auto k: file) {
                cout << "[ " << k << " ] " << endl;
                if(i[j].find(k)!=string::npos) {
                    found_matches.insert(i[j]);
                }
            }
        }
    }
    
    cout << "\t\t[ok]" << endl;
    //12 o'clock data haha
}

void classifier::show() {
   // system("clear");
    if(!exe) return;
    for(auto i: found_matches) {
        cout << "--- SYMPTOMS ----" << endl;
        cout << "\t\t" << i << endl;
    }
}

void classifier::relate() {

}

void classifier::question() {
    system("clear");
    ofstream writefile(NAMES, ios::app);
    
    for(auto i: found_matches) {
        cout << "Symp: [" << i << "]\t\t\t: ";
        char in;
        cin >> in;
        cin.ignore();

        switch(in) {
            case 'Y':
            case 'y':
            symptoms.insert(i);
            writefile << i << endl;
            break;

            case 'N':
            case 'n':
            break;

            default:
            cout << endl << "Error: Invalid input!!" << endl;
        }
    }

    writefile.close();
}
#endif