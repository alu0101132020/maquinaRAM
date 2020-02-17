#include "../include/ProgramMemory.hpp"

Registers::Registers() {
  regist.push_back(0);
}

Registers::Registers(const int &number) :
   regist(number, 0) {
     if (number <= 0)
        throw "error";
   }

Registers::~Registers() {}

int Registers::getReg(const int &index) {
  return regist[index];
}

void Registers::setReg(const int &index, int &value) {
  regist[index] = value;
}

std::vector<int> Registers::getAllReg() {
  return regist;
}

int Registers::numbOfReg(void) {
  return regist.size();
}

void Registers::writeRegisters() {
  for (int i = 0; i < regist.size(); i++) {
    std::cout << "|" << regist[i] << "|\n";
  }
}
