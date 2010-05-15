#include "engine.h"
#include "GL/glut.h"
#include <IL/il.h>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace Engine;

const int Window::WIDTH = 640;
const int Window::HEIGHT = 480;
const char* Window::NAME = "harald";

ObjectList Window::objects;

Window::Window(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow(NAME);
  glutDisplayFunc(&render);
  glutIdleFunc(&idle);
  glutTimerFunc(0,&timer,0);
  glutSpecialFunc(&keyboard);
  glViewport(0, 0, WIDTH, HEIGHT);
  glEnable(GL_TEXTURE_2D);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, WIDTH, HEIGHT, 0.0, 0.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void Base::loadImage(char* filename) {
  GLuint image;
  ILuint texid;
  ilInit();
  ilGenImages(1, &texid);
  ilBindImage(texid);
  if (ilLoadImage(filename)) {
    if (ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE)) {
      glGenTextures(1, &image);
      glBindTexture(GL_TEXTURE_2D, image);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
        ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
        ilGetData());
    }
  }
}

Object::Object(Base* engine) {
  this->engine = engine;
}

