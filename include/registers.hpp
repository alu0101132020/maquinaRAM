#pragma once

#include <vector>
#include <iostream>

class RegisterMemory {
  private:
    std::vector<int> regist;
  public:
    RegisterMemory();
    RegisterMemory(const int &number);
    ~RegisterMemory();

    int getReg(const int &number);
    void setReg(const int &index, int value);
    int numbOfReg(void);
    void writeRegisters();
    std::vector<int> getAllReg();
    void cleanRegisters(void);
    // friend std::ostream& operator<<(std::ostream& os, RegisterMemory& dt);
};
