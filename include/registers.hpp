#pragma once

#include <vector>
#include <iostream>

class RegisterMemory {
  private:
    std::vector<long long> regist;
  public:
    RegisterMemory();
    RegisterMemory(const int &number);
    ~RegisterMemory();

    long long getReg(const int &number);
    void setReg(const int &index, int value);
    int numbOfReg(void);
    void writeRegisters();
    std::vector<long long> getAllReg();
    void cleanRegisters(void);
    // friend std::ostream& operator<<(std::ostream& os, RegisterMemory& dt);
};
