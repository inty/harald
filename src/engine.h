#include <list>

using namespace std;

namespace Engine {

  class Object {
    public:
      virtual void draw() = 0;
      virtual void key(int key) = 0;
  };

  typedef list<Object*> ObjectList;

  class Window {
    public:
      Window(int argc, char* argv[]);
      void run();

      void add(Object* object);

    private:
      // needs to be static so we can send a function pointer to glut.. :/
      static void render();
      static void idle();
      static void timer(int time);
      static void keyboard(int key, int x, int y);

      static ObjectList objects;
  };

  class Base {
    public:
      Base(int argc, char* argv[]);

      void run();

    private:
      Window* window;
  };

  class Player : public Object {
    public:
      Player();
      void draw();
      void key(int key);
  };

}
