#include <vector>
#include <tuple>

class ProgramMemory {
private:
  std::vector < tuple < std::string instruct, int opt, int val >  lines;
  std::vector < std::pair <std::string tag, int numbLine> tags; 
public:
  ProgramMemory(const std::ifstream &file);
  ~ProgramMemory();

  int getReg(const int &number);
  int numbOfLines(void);
  void writeLines();
private:
  std::vector<int> getAllCode();
}
