#include "engine.h"
#include "GL/glut.h"
#include <iostream>

using namespace std;
using namespace Engine;

ObjectList Window::objects;

Window::Window(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320,320);
  glutCreateWindow("harald");
  glClearColor(0,0,0,0);
  gluOrtho2D(-5,5,-5,5);
  glutDisplayFunc(&render);
  glutIdleFunc(&idle);
  glutTimerFunc(0,&timer,0);
  glutSpecialFunc(&keyboard);
}

void Window::keyboard(int key, int x, int y) {
  for(ObjectList::const_iterator iter = objects.begin(),
    endIter = objects.end(); iter != endIter; ++iter) {
    Object *object = *iter;
    object->key(key);
  }
}

void Window::run() {
  glutMainLoop();
}

void Window::add(Object* object) {
  objects.push_back(object);
}

void Window::render() {
  glClear(GL_COLOR_BUFFER_BIT);

  float time = glutGet(GLUT_ELAPSED_TIME);

  for(ObjectList::const_iterator iter = objects.begin(),
    endIter = objects.end(); iter != endIter; ++iter) {
    Object *object = *iter;
    object->draw();
  }

  glFlush();
}

void Window::idle() {
}

void Window::timer(int time) {
  glutPostRedisplay();
  glutTimerFunc(1000/30,&timer,0);
}

Base::Base(int argc, char* argv[]) {
  window = new Window(argc, argv);
}

void Base::add(Object* object) {
  window->add(object);
}

void Base::run() {
  window->run();
}

