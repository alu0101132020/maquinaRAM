#include <vector>
#include <fstream>

class Tap {
  protected:
    std::vector<int> elements;
    int head;

  public:
    Tap();
    ~Tap();
  private:
    void moveForward();
};

class ReadTap : public Tap {
  public:
    ReadTap(const std::ifstream &file);
    void read(const int &number);
  private:
    void load();
};


class WriteTap : public Tap {
  public:
    void write(const int &number);
    int elementsWritten();
};
