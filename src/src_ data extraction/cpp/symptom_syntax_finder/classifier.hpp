#ifndef CLASSIFIER_H_INCLUDED
#define CLASSIFIER_H_INCLUDED
#include "tools.hpp"
#define FILE "database/symptoms/syntax/file.txt"
#define PARSED_DIR "databse/parsers/raw"
using namespace std;


class classifier {
    bool exe = false;
    set<string> found_matches;
    public:
    void check(), find(), relate(), question();
};

void classifier::check() {
    cout << "Checking file: [database/symptoms/syntax/file.txt]";
    if(tools::check_file("database/symptoms/syntax/file.txt")) {
        cout << "\t\t[ok]" << endl;
        exe = true;
    } else cout << "\t\t[failed]" << endl;

    //more checks in file should go here
}

void classifier::find() {
    if(!exe) return;
    vector<string> file {tools::read_file(FILE)};
    vector<string> file2 {tools::read_dir(PARSED_DIR)};
    cout << "Finding: [" << file.size() << "]";

    for(unsigned int i=0;i<file.size();i++) {
        for(unsigned int i1;i1<file2.size();i1++) {
            if(file2[i1].find(file[i])!=string::npos) {
                found_matches.insert(file2[i1]);
            }
        }
    }
    cout << "\t\t[ok]" << endl;
}

void classifier::relate() {

}

void classifier::question() {

}
#endif