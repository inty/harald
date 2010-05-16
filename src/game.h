#include "engine.h"

using namespace Engine;

namespace Game {

  class Player : public Object {
    public:
      Player(Base* engine);

      void draw();
      void key(int key);

    private:
      Texture* texture;
  };

  class Tree : public Object {
    public:
      Tree(Base* engine);

      void draw();
      void key(int key);

    private:
      Texture* texture;
  };
}
