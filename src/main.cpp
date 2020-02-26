#include <iostream>
#include <fstream>
#include "../include/RAMMachine.hpp"

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "El número de argumentos es incorrecto. Pase un fichero ";
    std::cerr << "con el nombre del programa, otro que contenga la cinta de ";
    std::cerr << "entrada y uno último con la cinta de salida\n";
    return 1;
  }

  std::string programFile = argv[1];
  std::string readFile = argv[2];
  std::string writeFile = argv[3];

  RAMMachine RM(programFile, readFile, writeFile);
  RM.writeState();


  return 0;
}
