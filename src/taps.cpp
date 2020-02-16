#include "taps.hpp"

Tap::Tap()
    : head(-1) {}


Tap::Tap() {}

void Tap::moveForward(void) {
  head++;
}

int Tap::elementsWritten(void) {
	return elements.size();
}

void ReadTap::load(std::ifstream& file) {
  if (file.is_open()) {
      while (file) {
        int readElement;
        file >> readElement;
        elements.push_back(readElement);
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
