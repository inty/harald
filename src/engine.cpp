#include "engine.h"
#include "GL/glut.h"
#include <iostream>

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
  Player* player = new Player();
  window->add(player);
}

void Base::run() {
  window->run();
}

Player::Player() {

}

void Player::draw() {
  glColor3f(1,0,0);
  glBegin(GL_QUADS);
  glVertex2f(-4,-4);
  glVertex2f(-4,-2);
  glVertex2f(-2,-2);
  glVertex2f(-2,-4);
  glEnd();
}
