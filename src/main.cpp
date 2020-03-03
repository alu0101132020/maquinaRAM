/**
 * Autor: Manuel Andrés Carrera.
 * Universidad: Universidad de La Laguna.
 * Curso: 3
 * Grado: Ingeniería informática.
 * Descripción: Código que implementa la máquina RAM que es capaz de ejecutar
 *    código en lenguaje ensamblador RAM.
 */

#include <iostream>
#include <fstream>
#include "../include/RAMMachine.hpp"

int main(int argc, char** argv) {
  if (argc != 4 && argc != 5) {
    std::cerr << "El número de argumentos es incorrecto. Pase un fichero ";
    std::cerr << "con el nombre del programa, otro que contenga la cinta de ";
    std::cerr << "entrada y uno último con la cinta de salida\n";
    return 1;
  }
  bool debugModeFlag = false;
  std::string programFile = argv[1];
  std::string readFile = argv[2];
  std::string writeFile = argv[3];
  std::string debMF = argv[4];
  if (debMF == "debug") {
    debugModeFlag = true;
  }

  RAMMachine RM(programFile, readFile, writeFile);
  RM.start(debugModeFlag);

  return 0;
}
