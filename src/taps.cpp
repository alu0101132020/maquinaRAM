#include "taps.hpp"

Tape::Tape()
    : head(-1) {}


Tape::Tape() {}

void Tape::moveForward(void) {
  head++;
}

int Tape::elementsWritten(void) {
	return elements.size();
}

void ReadTape::load(std::ifstream& file) {
  if (file.is_open()) {
      while (file) {
        int readElement;
        file >> readElement;
        elements.push_back(readElement);
        head++;
      }
      file.close();
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
