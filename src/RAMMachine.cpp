#include "../include/RAMMachine.hpp"

RAMMachine::RAMMachine(std::string &ramFile, std::string &inputFile, std::string &outputFile) :
    programMemory(ramFile), readTape(inputFile), writeTape(),
    programCounter(0), registerMemory(30) {}

void RAMMachine::writeState() {
  std::cout << "---------- Registros -----------\n\n";
  registerMemory.writeRegisters();
  std::cout << "---------- Programa -----------\n\n";
  programMemory.writeProgram();

}
