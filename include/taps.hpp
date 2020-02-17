#include <vector>
#include <fstream>

class Tape {
  protected:
    std::vector<int> elements;
    int head;

  public:
    Tape();
    ~Tape();
  private:
    void moveForward();
};

class ReadTape : public Tape {
  public:
    ReadTape(const std::ifstream &file);
    void read(const int &number);
  private:
    void load();
};


class WriteTape : public Tap {
  public:
    void write(const int &number);
    int elementsWritten();
};
