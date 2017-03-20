
#ifndef symptom_synx_crawlr_H_INCLUDED
#define symptom_synx_crawlr_H_INCLUDED
#define SYN_FILE "database/symptoms/syntax/file.txt"
#include "tools.hpp"
using namespace std;


class symptom_synx_crawl {
    private:
    string input;
    vector<string> file;
    bool exe = false;
    set<string> loaded_syntax;
    public:
    bool exe_classifier = false;
    void show(), run(), ini(string), write();
};

void symptom_synx_crawl::ini(string query) {
    cout << "Initializing: \t\t[" + query + "]";

    ifstream readfile(SYN_FILE);
    if(readfile.good()) {
        //load the whole lot into mem
        loaded_syntax = tools::read_file(SYN_FILE);
        readfile.close();
        cout << "[" << loaded_syntax.size() << " syntax loaded!]";
    }
    input = query;
    ifstream readfile1("DataFiles/symptoms.webmd.comdefault.htm.txt");
    if(readfile1.good()) {


        /* 

            should read the whole dir and take all the files into mem...
            .... could be an issue if files goes in the level of GB....

            per file implimentation should be used here in case of that!!
        */
        
        file = tools::read_file("DataFiles/symptoms.webmd.comdefault.htm.txt", false);
        cout << "\t\t[ok]" << endl;
        exe = true;
    }
    else cout << "\t\t[failed]" << endl;
    readfile1.close();
}

void symptom_synx_crawl::run() {
    if(!exe) return;
    cout << "Executing: \t\t[run]";
    if(file.size() < 1) {
        cout << "\t\t[failed]" << endl;
        exit(1);
    }
    for(unsigned int i=0;i<file.size();i++){
        if(file[i].find(input)!=string::npos) {
            if(i < file.size() - 3) {
                string temp = file[i+1] + " " + file[i+2];
                loaded_syntax.insert(temp);
            }
            else cout << "..." << endl;
        }
    }
    cout << "\t\t[ok]" << endl;
}

void symptom_synx_crawl::show() {
    if(!exe) return;
    system("clear");
    cout << "---- KEY WORDS ----" << endl;
    cout << "Number: " << loaded_syntax.size() << endl << endl;
    int count = 1;
    for(auto i=loaded_syntax.begin();i!=loaded_syntax.end();i++, count++) {
        cout << count << " -- " << *i << endl;
    }
}

void symptom_synx_crawl::write() {
    if(!exe || loaded_syntax.size() < 1) return;
    
    cout << "Writing: [database/symptoms/syntax/file.txt]: ";
    ofstream writefile("database/symptoms/syntax/file.txt", ios::trunc);
    for(auto i: loaded_syntax) writefile << i << endl;
    writefile.close();
    cout << "\t\t[ok]" << endl;

    exe_classifier = true;

}

#endif