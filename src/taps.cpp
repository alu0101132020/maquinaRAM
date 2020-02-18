#include "../include/taps.hpp"

Tape::Tape()
    : head(-1) {}


Tape::~Tape() {}

void Tape::moveForward(void) {
  head++;
}

int WriteTape::elementsWritten(void) {
	return Tape::elements.size();
}

ReadTape::ReadTape(std::string& file) {
  load(file);
}

void ReadTape::load(std::string& file) {
  std::ifstream inFile;
  if (inFile.is_open()) {
      while (inFile) {
        int readElement;
        inFile >> readElement;
        elements.push_back(readElement);
        head++;
      }
      inFile.close();
  }
}



/*
if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      elements.push_back(line);
      head++;
    }
    file.close();
}
*/
