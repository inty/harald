#include <list>

using namespace std;

namespace Engine {

  class Base;

  class Object {
    public:
      Object(Base* engine);

      virtual void draw() = 0;
      virtual void key(int key) = 0;

    protected:
      Base* engine;
  };

  typedef list<Object*> ObjectList;

  class Window {
    public:
      const static int WIDTH;
      const static int HEIGHT;
      const static char* NAME;

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
      void add(Object* object);

      void loadImage(char* filename);

    private:
      Window* window;
  };

}
