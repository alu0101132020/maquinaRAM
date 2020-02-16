#pragma once

#include <vector>
#include <iostream>

class Registers {
  private:
    std::vector<int> regist;
  public:
    Registers();
    Registers(const int &number);
    ~Registers();

    int getReg(const int &number);
    void setReg(const int &index, int &value);
    int numbOfReg(void);
    void writeRegisters();
  private:
    std::vector<int> getAllReg();
};
