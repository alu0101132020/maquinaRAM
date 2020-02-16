#include "../include/registers.hpp"

int main(void) {
  Registers A;
  Registers B(20);
  A.writeRegisters();
  B.writeRegisters();
}
