#include <iostream>
#include "engine.cpp"

using namespace std;
using namespace Engine;

int main(int argc, char* argv[]) {
  Base engine(argc, argv);
  engine.run();
  return 0;
}
