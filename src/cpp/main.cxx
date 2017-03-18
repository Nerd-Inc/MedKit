#include "parser.hpp"
using namespace std;

int main(int argc, char** argv) {
   parse parse;

   parse.ini("sample.txt", "DEF");
   parse.file();
}