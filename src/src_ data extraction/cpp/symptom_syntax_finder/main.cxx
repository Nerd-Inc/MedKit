#include "finder.hpp"
using namespace std;

int main(int argc, char** argv) {
   finder finder;

   finder.ini("headache");
   finder.run();
   finder.show();


   return 0;
}