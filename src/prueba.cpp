#include "../include/tapes.hpp"

int main (void) {
  std::string hola = "myfile.txt";
  WriteTape WR(hola);
  WR.write(1);
  WR.writeOnFile();
}