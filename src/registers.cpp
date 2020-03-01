#include "../include/registers.hpp"

RegisterMemory::RegisterMemory() {
  regist.push_back(0);
}

RegisterMemory::RegisterMemory(const int &number) :
   regist(number, 0) {
     if (number <= 0)
        throw "error";
   }

RegisterMemory::~RegisterMemory() {}

int RegisterMemory::getReg(const int &index) {
  return regist[index];
}

void RegisterMemory::setReg(const int &index, int value) {
  regist[index] = value;
}

void RegisterMemory::cleanRegisters(void) {
  for (int i = 0; i < regist.size(); i++) {
    regist[i] = 0;
  }
}

std::vector<int> RegisterMemory::getAllReg() {
  return regist;
}

int RegisterMemory::numbOfReg(void) {
  return regist.size();
}

void RegisterMemory::writeRegisters() {
  for (int i = 0; i < regist.size(); i++) {
    std::cout << "| " << regist[i] << " | ";
  }
  std::cout << "\n";
}

// std::ostream& operator<<(std::ostream& os, RegisterMemory& rm) {
//   for (int i = 0; i < rm.getAllReg().size(); i++) {
//     os << "|" << rm.getAllReg()[i] << "|\n";
//   }
// }
