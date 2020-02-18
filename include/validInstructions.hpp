#pragma once

#include <vector>
#include <fstream>
#include <iostream>

class ValidInstructions {
  private:
    std::vector < std::pair < std::string, std::string > > definedInstructions;
  public:
    ValidInstructions(const std::string &file);
    ~ValidInstructions();

    std::string getInstCode(std::string instName);
    std::string getInstName(std::string instCode);
    void writeInst(void);
};
