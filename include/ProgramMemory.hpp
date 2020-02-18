#pragma once
#include <vector>
#include <tuple>
#include <algorithm>

#include "validInstructions.hpp"
// #include "../src/auxFunctions.cpp"


class ProgramMemory {
  private:
    std::vector <std::tuple <int, int, int> >  lines;
    std::vector <std::pair <std::string, int > > tags;
    ValidInstructions VI;

  public:
    ProgramMemory(const std::string &file);
    ~ProgramMemory();

    std::tuple <int, int, int> getLine(const int &index);
    void setLine(const int &index, std::tuple < int, int, int> &value);
    std::vector < std::tuple <int, int, int> > getAllProgram();
    int numbOfLines(void);
    void writeProgram();    
};
