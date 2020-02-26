#include "../include/validInstructions.hpp"



ValidInstructions::ValidInstructions(const std::string &file) {
  std::ifstream inFile;
  inFile.open(file);
  if (!inFile) {
    std::cout << "Unable to open file";
    exit(1); // terminate with error
  }
  std::string str1, str2;
  std::pair < std::string, std::string > dummy;
  while (!inFile.eof()) {
    inFile >> str1;
    inFile >> str2;
    dummy.first = str1;
    dummy.second = str2;
    definedInstructions.push_back(dummy);
  }
  definedInstructions.pop_back();
  inFile.close();
}

std::string ValidInstructions::getInstCode(std::string instName) {
  for (int i = 0; i < definedInstructions.size(); i++) {
    if (definedInstructions[i].first == instName)
      return definedInstructions[i].second;
  }
  return "-1";
}

std::string ValidInstructions::getInstName(std::string instCode) {
  for (int i = 0; i < definedInstructions.size(); i++) {
    if (definedInstructions[i].second == instCode)
      return definedInstructions[i].first;
  }
  return "-1";
}

void ValidInstructions::writeInst(void) {
  for (int i = 0; i < definedInstructions.size(); i++) {
    std::cout << definedInstructions[i].first << " " << definedInstructions[i].second << std::endl;
  }
}

ValidInstructions::~ValidInstructions() {}
