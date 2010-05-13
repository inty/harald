#include "engine.h"
#include "GL/glut.h"

Engine::Window::Window(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320,320);
  glutCreateWindow("harald");
  glClearColor(0,0,0,0);
  gluOrtho2D(-5,5,-5,5);
  glutDisplayFunc(&render);
}

void Engine::Window::run() {
  glutMainLoop();
}

void Engine::Window::render() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1,0,0);
  glBegin(GL_TRIANGLES);
  glVertex2f(3,-4);
  glVertex2f(3.5,-3);
  glVertex2f(4,-4);
  glEnd();
  glFlush();
}

Engine::Base::Base(int argc, char* argv[]) {
  window = new Window(argc, argv);
}

void Engine::Base::run() {
  window->run();
}

