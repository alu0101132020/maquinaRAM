#include <iostream>
#include <fstream>

#include "taps.hpp"

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "El número de argumentos es incorrecto. Pase un fichero";
    std::cerr << "con el nombre del programa, otro que contenga la cinta de";
    std::cerr << "entrada y uno último con la cinta de salida\n";
    return 1;
  }

  std::ifstream programFile;
  std::ifstream readTapFile;
  std::ifstream writeTapFile;
  programFile.open(argv[1]);
  readTapFile.open(argv[2]);
  writeTapFile.open(argv[3]);

  if ((!f_programa.is_open()) || (!f_cinta_lectura.is_open()) ||
      (!f_cinta_escritura.is_open())) {
    std::cerr << "Error abriendo alguno de los ficheros\n";
    return 2;
  }



  return 0;
}
