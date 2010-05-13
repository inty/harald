
namespace Engine {

  class Window {
    public:
      Window(int argc, char* argv[]);
      void run();

      // needs to be static so we can send a function pointer to glut.. :/
      static void render();
  };

  class Base {
    public:
      Base(int argc, char* argv[]);

      void run();

    private:
      Window* window;
  };

}
