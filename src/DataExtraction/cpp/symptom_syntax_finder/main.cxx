#include "symptom_synx_crawl.hpp"
#include "classifier.hpp"
using namespace std;

int main(int argc, char** argv) {
   
   symptom_synx_crawl symptom_synx_crawl;

   symptom_synx_crawl.ini("headache");
   symptom_synx_crawl.run();
   //symptom_synx_crawl.show();
   symptom_synx_crawl.write();

  
  if(!symptom_synx_crawl.exe_classifier) return 1;
   classifier classi;
   classi.check();
   classi.find();
   classi.relate();
   classi.question();
   //classi.show();

   return 0;
}