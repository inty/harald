#include "engine.h"

using namespace Engine;

namespace Game {

  class Player : public Object {
    public:
      Player();
      void draw();
      void key(int key);
  };

}
