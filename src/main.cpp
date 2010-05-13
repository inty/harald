#include <iostream>
#include "game.h"

using namespace std;
using namespace Engine;
using namespace Game;

int main(int argc, char* argv[]) {
  Base* engine = new Base(argc, argv);
  Player* player = new Player();
  engine->add(player);
  engine->run();
  return 0;
}
