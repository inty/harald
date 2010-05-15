#include "engine.h"

using namespace Engine;

namespace Game {

  class Player : public Object {
    public:
      Player(Base* engine);

      void draw();
      void key(int key);
  };

}
