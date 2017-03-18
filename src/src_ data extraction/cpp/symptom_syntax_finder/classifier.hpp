#ifndef CLASSIFIER_H_INCLUDED
#define CLASSIFIER_H_INCLUDED
#include "tools.hpp"
#define FILE "database/symptoms/syntax/file.txt"
using namespace std;


class classifier {
    bool exe = false;
    public:
    void check(), find(), relate(), question();
};

void classifier::check() {
    cout << "Checking file: [database/symptoms/syntax/file.txt]";
    if(check_file("database/symptoms/syntax/file.txt")) {
        cout << "\t\t[ok]" << endl;
        exe = true;
    } else cout << "\t\t[failed]" << endl;

    //more checks in file should go here
}

void classifier::find() {
    vector<string> file {tools::read_file(FILE)};
    vector<string> file2 {tools::read_dir(PARSED_DIR)};

    
}

void classifier::relate() {

}

void classifier::question() {

}
#endif