#include <list>
#include <map>
#include "GL/glut.h"
#include <IL/il.h>

using namespace std;

namespace Engine {

  class Base;

  class Texture {
    public:
      Texture(GLint internalFormat, GLsizei width, GLsizei height,
          GLenum format, GLvoid* data);

      GLint getInternalFormat();
      GLsizei getWidth();
      GLsizei getHeight();
      GLenum getFormat();
      GLvoid* getData();

    private:
      GLint internalFormat;
      GLsizei width;
      GLsizei height;
      GLenum format;
      GLvoid* data;
  };

  class Object {
    public:
      Object(Base* engine);

      virtual void draw() = 0;
      virtual void key(int key) = 0;

    protected:
      Base* engine;
  };

  typedef list<Object*> ObjectList;
  typedef map<char*,Texture*> TextureMap;

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
      static void timer(int time);
      static void keyboard(int key, int x, int y);

      static ObjectList objects;
  };

  class Base {
    public:
      Base(int argc, char* argv[]);

      void run();
      void add(Object* object);

      Texture* loadImage(char* filename);
      void bindTexture(Texture* texture);

    private:
      Window* window;

      TextureMap textures;
  };
}

