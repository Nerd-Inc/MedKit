
#ifndef symptom_synx_crawlr_H_INCLUDED
#define symptom_synx_crawlr_H_INCLUDED
#include "tools.hpp"
using namespace std;


class symptom_synx_crawl {
    private:
    string input;
    vector<string> ex_syntax, file;
    bool exe = false;
    public:
    void show(), run(), ini(string), write();
};

void symptom_synx_crawl::ini(string query) {
    cout << "Initializing: \t\t[" + query + "]";
    input = query;
    ifstream readfile("DataFiles/symptoms.webmd.comdefault.htm.txt");
    if(readfile.good()) {


        /* 

            should read the whole dir and take all the files into mem...
            .... could be an issue if files goes in the level of GB....

            per file implimentation should be used here in case of that!!
        */
        
        file = tools::read_file("DataFiles/symptoms.webmd.comdefault.htm.txt");
        cout << "\t\t[ok]" << endl;
        exe = true;
    }
    else cout << "\t\t[failed]" << endl;
}

void symptom_synx_crawl::run() {
    if(!exe) return;
    cout << "Executing: \t\t[run] ...";
    if(file.size() < 1) {
        cout << "\t\t[failed]" << endl;
        exit(1);
    }
    for(unsigned int i=0;i<file.size();i++){
        if(file[i].find(input)!=string::npos) {
            if(i < file.size() - 3) {
                string temp = file[i+1] + " " + file[i+2];
                ex_syntax.push_back(temp);
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
    cout << "Number: " << ex_syntax.size() << endl << endl;
    for(unsigned int i=0;i<ex_syntax.size();i++) {
        cout << i+1 << " -- " << ex_syntax[i] << endl;
    }
}

void symptom_synx_crawl::write() {
    if(!exe || ex_syntax.size() < 1) return;
    
    cout << "Writing: [database/symptoms/syntax/file.txt]: ";
    ofstream writefile("database/symptoms/syntax/file.txt", ios::app);
    for(auto i: ex_syntax) writefile << i << endl;
    writefile.close();
    cout << "\t\t[ok]" << endl;

}

#endif