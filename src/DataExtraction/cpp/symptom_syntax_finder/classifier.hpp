#ifndef CLASSIFIER_H_INCLUDED
#define CLASSIFIER_H_INCLUDED
#include "tools.hpp"
#define _FILE "database/symptoms/syntax/file.txt"
#define NAMES "database/symptoms/names/files.txt"
#define LIST_SYMS "database/symptoms/names/list.txt"
#define PARSED_DIR "DataFiles"
using namespace std;


class classifier {
    bool exe = false;
    set<string> found_matches;
    public:
    void check(), find(), relate(), question(), show();
    set<string> in_list, out_list;
};

void classifier::check() {
    cout << "Checking file: [" << _FILE << "]";
    if(tools::check_file(_FILE)) {
        cout << "\t\t[ok]" << endl;
        exe = true;
    } else cout << "\t\t[failed]" << endl;

    //more checks in file should go here
}

void classifier::find() {
    if(!exe) return;
    vector<string> file {tools::read_file(_FILE, false)};
    vector<vector<string>> file2 {tools::read_dir(PARSED_DIR)};
    cout << "Finding: [ RUNTIME: " << file.size() * file2.size() << "]";

    if(file.size() < 1) {
        cout << "\t\t[failed]" << endl;
        exit(1);
    }

    cout << "\tDataFiles: [" << file2.size() << "]";
    for(auto i: file2) { //vector<vector<string>>
        //cout << "in: " << i.size() << endl;
        for(unsigned int j=0;j<i.size();j++) { //vector<string>>
            //cout << "-----> " << i[j] << endl;
            //cout << "Scanning..." << endl;
            for(auto k: file) {
                //cout << "[ " << k << " ] " << endl;
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
    if(!exe) return;
    cout << "Crossing against list: [" << LIST_SYMS << "]";
    vector<string> file_temp;
    if(tools::check_file(LIST_SYMS)) {
        file_temp = tools::read_file(LIST_SYMS, false );
    } else {
        cout << "\t\t[failed]" << endl;
        exit(1);
    }

    for(auto i: found_matches) {
        bool found = false;
        for(auto j: file_temp) {
            if(i == j) {
                in_list.insert(i);
                found = true;
                break;
            }
        }
        if(!found) out_list.insert(i);
    }
    cout << "\t\t[ok]" << endl;
}

void classifier::question() {
    if(!exe || out_list.size() < 1) {
        if(out_list.size() < 1) 
            cout << "[ERROR]: No matches found for manual verifcation.... exiting!" << endl;
        exit(1);
    }
    system("clear");
    cout << "Manual Verification: DataSet[" << out_list.size() << "]" << endl;
    ofstream writefile(NAMES, ios::trunc);
    
    for(auto i=found_matches.begin();i!=found_matches.end();i++) {
        cout << "Symp: [" << *i << "]\t\t\t: ";
        char in;
        cin >> in;
        cin.ignore();

        switch(in) {
            case 'Y':
            case 'y':
            in_list.insert(*i);
            //writefile << *i << endl;
            break;

            case 'N':
            case 'n':
            break;

            default:
            --i;
            cout << endl << "Error: Invalid input!!" << endl;
        }
    }

    for(auto i=in_list.begin();i!=in_list.end();i++) writefile << *i << endl;
    cout << "\t\t[ok]" << endl;

    writefile.close();
}
#endif