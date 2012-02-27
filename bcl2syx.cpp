#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main (int argc, char *argv[]) {

  if(argc < 1) {
    printf("Please provide input file!");
    return 0;
  }

  std::ifstream inf(argv[1]);

  char syxHeader[7] = {0xf0, 0x00, 0x20, 0x32, 0x7f, 0x15, 0x20};
  char countMsb = 0;
  char countLsb = 0;
  char textLine[256];
  char syxEnd = 0xf7;
 
  while(!inf.getline(textLine, 256).eof())
  {
     cout << std::string(&syxHeader[0], 7) << countMsb << countLsb << textLine << syxEnd;
     if( (countLsb = (countLsb+1)%256) == 0)
       ++countMsb;
  }

  return 0;
}
