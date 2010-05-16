#include <iostream>
#include "game.h"

using namespace std;
using namespace Engine;
using namespace Game;

int main(int argc, char* argv[]) {
  Base* engine = new Base(argc, argv);
  Grass* grass = new Grass(engine);
  Player* player = new Player(engine);
  Tree* tree = new Tree(engine);
  engine->add(grass);
  engine->add(tree);
  engine->add(player);
  engine->run();
  return 0;
}
