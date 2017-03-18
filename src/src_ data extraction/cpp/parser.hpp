/*

syntax style--->

    [query] -> (is(a)) = DEF

*/

#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include "tools.hpp"
using namespace std;


class parse {
    private:
    string input, type;
    public:
    void file(), _string(), ini(string, string);
};


void parse::file() {
    vector<string> file = tools::read_file(input);

    for(auto i: file) {
        if(type == "DEF") {
            string command = input + " is a"; //should change based on statistics
            if(i.find(command)) {
                //either show entire symptom || show entire sentence || write to file
                cout << "\t\t\t" + i << endl;
                continue;
            }
        }
    }
}

void parse::_string() {

}

void parse::ini(string in, string ty) {
    input = in;
    type = ty;
}
#endif
